﻿#ifndef _OPENCL_H_
#define _OPENCL_H_

#ifdef __cplusplus
extern "C" {
#endif

// IntelやAMDのGPUでZeroCopyするにはメモリー境界をこの値にしないといけない
#define MEM_UNIT 4096

extern int OpenCL_method;

int init_OpenCL(unsigned int unit_size, int *src_max);
int free_OpenCL(void);
void info_OpenCL(char *buf, int buf_size);

int gpu_copy_blocks(
	unsigned char *data,
	unsigned int unit_size,
	int src_num);

int gpu_multiply_blocks(
	int src_num,			// Number of multiplying source blocks
	unsigned short *mat,	// Matrix of numbers to multiply by
	unsigned short *mat2,	// Set to calculate 2 blocks at once
	unsigned char *buf,		// Products go here
	unsigned int len);		// Byte length

int gpu_finish(void);

#ifdef __cplusplus
}
#endif

#endif
