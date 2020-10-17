#ifndef __SAMPLE_FACE_DETECT__
#define __SAMPLE_FACE_DETECT__

#include <assert.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <utils/plat_log.h>

#include "media/mpi_sys.h"
#include "mm_comm_sys.h"
#include "mm_common.h"
#include "mpp_venc.h"
#include "mpp_vi.h"
#include "nna.h"
#include "osd_helper.h"
#include "tmessage.h"
#include "tsemaphore.h"

#include "NNARegister.h"
#include "awMemory.h"
#include "aw_g2d.h"
#include "image_utils.h"
#include "ion_alloc.h"
#include "nna_driver.h"
#include "show.h"
#include "timing.h"

#ifdef __cplusplus
extern "C" {
#endif /* End of #ifdef __cplusplus */

#define TEST_FRAME_NUM (800)  // 测试帧数
#define SAVE_H264_FILE        // 保存H264文件
#define VI_CAPTURE_WIDTH (1920)
#define VI_CAPTURE_HIGHT (1080)

#define NNA_CALC_WIDTH (1920)
#define NNA_CALC_HIGHT (1080)

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

pthread_mutex_t g_stResult_lock = PTHREAD_MUTEX_INITIALIZER;

typedef enum MPP_STATETYPE { MPP_StateIdle = 0X70000000, MPP_StateFilled, MPP_StateMax = 0X7FFFFFFF } MPP_STATETYPE;

typedef struct _Picture_Params {
    MPP_STATETYPE ePicState;
    VIDEO_FRAME_INFO_S stVideoFrame;
    pthread_mutex_t lockPicture;

} Picture_Params;

typedef void* (*ProcessFuncType)(void* pThreadData);
typedef struct _THREAD_DATA {
    ProcessFuncType ProcessFunc;
    pthread_t mThreadID;
    void* pPrivateData;

} THREAD_DATA;

typedef struct _NNA_Params {
    int iFrameNum;

    PIXEL_FORMAT_E ePixFmt;
    int iPicWidth;
    int iPicHeight;
    int iFrmRate;

    AW_HANDLE pEVEHd;
} NNA_Params;

typedef struct _UserConfig {
    VirVi_Params stVirViParams[VirVi_MAX];
    VENC_Params stVENCParams;
    NNA_Params stNNAParams;
    THREAD_DATA stThreadData[PROC_MAX];
    cdx_sem_t mSemExit;
} UserConfig;

typedef struct _test_info_t {
    AwG2d* aw_g2d;
    struct AwMemOpsS* aw_mem;

    int nna_fd;
    int scale_num;
    unsigned int nna_buf_phy;
    unsigned char* nna_buf_vir;
    unsigned int nna_buf_size;

    unsigned int src_buf_phy;
    unsigned char* src_buf_vir;
    unsigned int src_buf_size;

} test_info_t;

int xregw2(int reg_base, int result, unsigned int a2)
{
    *(uint32_t*)(reg_base + result) = a2;
    return result;
}
int xregr2(int reg_base, unsigned int a1)
{
  return *(uint32_t *)(reg_base + a1);
}
void * xreg_open(unsigned int a1)
{
  unsigned int offset; // r4
  int fd; // r0
  void *result; // r0

  offset = a1;
  fd = open("/dev/mem", 2050);
  if ( fd < 0 )
    return (void *)printf("open(/dev/mem) failed.[%x]", offset);
  result = mmap(0, 0x20000u, 3, 1, fd, offset);
  return result;
}
int nna_conv_enable2(int reg_base, int a1, int a2)
{
    int v2;  // r4

    v2 = a1;
    while (!xregr2(reg_base, 0x300Cu))
        ;
    if (v2 == 1) xregw2(reg_base, 0x30D4u, 1u);
    xregw2(reg_base, 0x7008u, 1u);
    xregw2(reg_base, 0x5008u, 1u);
    xregw2(reg_base, 0x6008u, 1u);
    xregw2(reg_base, 0x4008u, 1u);
    return xregw2(reg_base, 0x3010u, 1u);
}
int nna_sdp_enable2(int reg_base, int a1, int a2)
{
    int v2;  // r4

    v2 = a2;
    if (a1 == 1) xregw2(reg_base, 0x90DCu, 0xFu);
    if (v2) xregw2(reg_base, 0x8008u, 1u);
    return xregw2(reg_base, 0x9038u, 1u);
}

extern int64_t CDX_GetSysTimeUsMonotonic();
#ifdef __cplusplus
}
#endif /* End of #ifdef __cplusplus */

#endif
