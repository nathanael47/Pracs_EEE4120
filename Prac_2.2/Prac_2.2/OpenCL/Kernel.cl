
//TODO: set your arguments for the kernel. Note that you have to indicate if the argument is global or local. Global arguments are accessable by both host and this target device. While local can only be accessed by the device running this kernel. eg __global int* inputMatrixA, __local int* groupMemory

__kernel void matrixMultiplication(__global int* inputMatrixA,__global int* inputMatrixB,__global int output[]){
	//work item and work groups numbers
	int workItemNum = get_global_id(0); //Work item ID
	int workGroupNum = get_group_id(0); //Work group ID
	int localGroupID = get_local_id(0); //Work items ID within each work group
	
	//memory buffers
	int arg1 = *inputMatrixA;;
	int arg2 = *inputMatrixB; 
	int out = *output;
	int sizes = 3;
	uint global_addr = workItemNum;
	//printf(" %i \n",sizes);
	//TODO: program your kernel here
	output[localGroupID + sizes*workGroupNum] = localGroupID*0;

	barrier(CLK_LOCAL_MEM_FENCE);
	if (localGroupID == 0){
		for (int i = 0; i < sizes ; i++){
			for (int j = 0; j < sizes ; j++){
				output[workItemNum + i] += (i+1)*(j+1);
			}
		}
	} 

}	
	
	




