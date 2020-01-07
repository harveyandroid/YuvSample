//
// Created by Admin on 2020/1/6 0006.
//

#include <jni.h>
#include "libyuv.h"
#include "YuvUtil.h"
#include <cstring>
#include <ctime>

using namespace libyuv;
extern "C"
JNIEXPORT jint JNICALL
Java_com_avatarcn_yuv_YuvUtil_NV21ToI420(JNIEnv *env, jobject instance,
                                         jbyteArray input_, jbyteArray output_,
                                         jint width, jint height) {
    jbyte *srcData = env->GetByteArrayElements(input_, NULL);
    jbyte *dstData = env->GetByteArrayElements(output_, NULL);
    jint src_y_size = width * height;
    jint src_u_size = (width >> 1) * (height >> 1);

    jbyte *src_nv21_y_data = srcData;
    jbyte *src_nv21_vu_data = srcData + src_y_size;

    jbyte *src_i420_y_data = dstData;
    jbyte *src_i420_u_data = dstData + src_y_size;
    jbyte *src_i420_v_data = dstData + src_y_size + src_u_size;

    jint result = NV21ToI420((const uint8_t *) src_nv21_y_data, width,
                             (const uint8_t *) src_nv21_vu_data, width,
                             (uint8_t *) src_i420_y_data, width,
                             (uint8_t *) src_i420_u_data, width >> 1,
                             (uint8_t *) src_i420_v_data, width >> 1,
                             width, height);
    env->ReleaseByteArrayElements(input_, srcData, 0);
    env->ReleaseByteArrayElements(output_, dstData, 0);
    return result;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_avatarcn_yuv_YuvUtil_RotateI420(JNIEnv *env, jobject type,
                                         jbyteArray input_, jbyteArray output_,
                                         jint width, jint height,
                                         jint rotation) {
    jbyte *srcData = env->GetByteArrayElements(input_, NULL);
    jbyte *dstData = env->GetByteArrayElements(output_, NULL);
    jint src_i420_y_size = width * height;
    jint src_i420_u_size = (width >> 1) * (height >> 1);
    jbyte *src_i420_y_data = srcData;
    jbyte *src_i420_u_data = srcData + src_i420_y_size;
    jbyte *src_i420_v_data = srcData + src_i420_y_size + src_i420_u_size;

    jbyte *dst_i420_y_data = dstData;
    jbyte *dst_i420_u_data = dstData + src_i420_y_size;
    jbyte *dst_i420_v_data = dstData + src_i420_y_size + src_i420_u_size;

    jint result = I420Rotate((const uint8_t *) src_i420_y_data, width,
                             (const uint8_t *) src_i420_u_data, width >> 1,
                             (const uint8_t *) src_i420_v_data, width >> 1,
                             (uint8_t *) dst_i420_y_data, height,
                             (uint8_t *) dst_i420_u_data, height >> 1,
                             (uint8_t *) dst_i420_v_data, height >> 1,
                             width, height,
                             (RotationMode) rotation);

    env->ReleaseByteArrayElements(input_, srcData, 0);
    env->ReleaseByteArrayElements(output_, dstData, 0);
    return result;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_avatarcn_yuv_YuvUtil_ScaleI420(JNIEnv *env, jobject type,
                                        jbyteArray src_, jint width, jint height,
                                        jbyteArray dst_, jint dst_width, jint dst_height,
                                        jint mode) {
    jbyte *srcData = env->GetByteArrayElements(src_, NULL);
    jbyte *dst_data = env->GetByteArrayElements(dst_, NULL);

    jint src_i420_y_size = width * height;
    jint src_i420_u_size = (width >> 1) * (height >> 1);
    jbyte *src_i420_y_data = srcData;
    jbyte *src_i420_u_data = srcData + src_i420_y_size;
    jbyte *src_i420_v_data = srcData + src_i420_y_size + src_i420_u_size;

    jint dst_i420_y_size = dst_width * dst_height;
    jint dst_i420_u_size = (dst_width >> 1) * (dst_height >> 1);
    jbyte *dst_i420_y_data = dst_data;
    jbyte *dst_i420_u_data = dst_data + dst_i420_y_size;
    jbyte *dst_i420_v_data = dst_data + dst_i420_y_size + dst_i420_u_size;

    jint result = I420Scale((const uint8_t *) src_i420_y_data, width,
                            (const uint8_t *) src_i420_u_data, width >> 1,
                            (const uint8_t *) src_i420_v_data, width >> 1,
                            width, height,
                            (uint8_t *) dst_i420_y_data, dst_width,
                            (uint8_t *) dst_i420_u_data, dst_width >> 1,
                            (uint8_t *) dst_i420_v_data, dst_width >> 1,
                            dst_width, dst_height,
                            (FilterMode) mode);

    env->ReleaseByteArrayElements(src_, srcData, 0);
    env->ReleaseByteArrayElements(dst_, dst_data, 0);
    return result;
}


extern "C"
JNIEXPORT jint JNICALL
Java_com_avatarcn_yuv_YuvUtil_MirrorI420(JNIEnv *env, jobject type,
                                         jbyteArray src_, jint width, jint height,
                                         jbyteArray dst_) {
    jbyte *src_data = env->GetByteArrayElements(src_, NULL);
    jbyte *dst_data = env->GetByteArrayElements(dst_, NULL);

    jint src_i420_y_size = width * height;
    jint src_i420_u_size = (width >> 1) * (height >> 1);

    jbyte *src_i420_y_data = src_data;
    jbyte *src_i420_u_data = src_data + src_i420_y_size;
    jbyte *src_i420_v_data = src_data + src_i420_y_size + src_i420_u_size;

    jbyte *dst_i420_y_data = dst_data;
    jbyte *dst_i420_u_data = dst_data + src_i420_y_size;
    jbyte *dst_i420_v_data = dst_data + src_i420_y_size + src_i420_u_size;

    jint result = I420Mirror((const uint8_t *) src_i420_y_data, width,
                             (const uint8_t *) src_i420_u_data, width >> 1,
                             (const uint8_t *) src_i420_v_data, width >> 1,
                             (uint8_t *) dst_i420_y_data, width,
                             (uint8_t *) dst_i420_u_data, width >> 1,
                             (uint8_t *) dst_i420_v_data, width >> 1,
                             width, height);
    env->ReleaseByteArrayElements(src_, src_data, 0);
    env->ReleaseByteArrayElements(dst_, dst_data, 0);
    return result;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_avatarcn_yuv_YuvUtil_CropI420(JNIEnv *env, jobject type,
                                       jbyteArray src_, jint width, jint height,
                                       jbyteArray dst_, jint dst_width, jint dst_height,
                                       jint left, jint top) {
    //裁剪的区域大小不对
    if (left + dst_width > width || top + dst_height > height) {
        return -1;
    }

    //left和top必须为偶数，否则显示会有问题
    if (left % 2 != 0 || top % 2 != 0) {
        return -1;
    }
    jint src_length = env->GetArrayLength(src_);
    jbyte *src_i420_data = env->GetByteArrayElements(src_, NULL);
    jbyte *dst_i420_data = env->GetByteArrayElements(dst_, NULL);


    jint dst_i420_y_size = dst_width * dst_height;
    jint dst_i420_u_size = (dst_width >> 1) * (dst_height >> 1);

    jbyte *dst_i420_y_data = dst_i420_data;
    jbyte *dst_i420_u_data = dst_i420_data + dst_i420_y_size;
    jbyte *dst_i420_v_data = dst_i420_data + dst_i420_y_size + dst_i420_u_size;

    jint result = ConvertToI420((const uint8_t *) src_i420_data, src_length,
                                (uint8_t *) dst_i420_y_data, dst_width,
                                (uint8_t *) dst_i420_u_data, dst_width >> 1,
                                (uint8_t *) dst_i420_v_data, dst_width >> 1,
                                left, top,
                                width, height,
                                dst_width, dst_height,
                                kRotate0, FOURCC_I420);

    env->ReleaseByteArrayElements(src_, src_i420_data, 0);
    env->ReleaseByteArrayElements(dst_, dst_i420_data, 0);
    return result;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_avatarcn_yuv_YuvUtil_I420ToNV21(JNIEnv *env, jobject type,
                                         jbyteArray i420Src,
                                         jbyteArray nv21Src,
                                         jint width, jint height) {

    jbyte *src_i420_data = env->GetByteArrayElements(i420Src, NULL);
    jbyte *src_nv21_data = env->GetByteArrayElements(nv21Src, NULL);

    jint src_y_size = width * height;
    jint src_u_size = (width >> 1) * (height >> 1);

    jbyte *src_i420_y_data = src_i420_data;
    jbyte *src_i420_u_data = src_i420_data + src_y_size;
    jbyte *src_i420_v_data = src_i420_data + src_y_size + src_u_size;

    jbyte *src_nv21_y_data = src_nv21_data;
    jbyte *src_nv21_vu_data = src_nv21_data + src_y_size;


    jint result = I420ToNV21(
            (const uint8_t *) src_i420_y_data, width,
            (const uint8_t *) src_i420_u_data, width >> 1,
            (const uint8_t *) src_i420_v_data, width >> 1,
            (uint8_t *) src_nv21_y_data, width,
            (uint8_t *) src_nv21_vu_data, width,
            width, height);
    env->ReleaseByteArrayElements(i420Src, src_i420_data, 0);
    env->ReleaseByteArrayElements(nv21Src, src_nv21_data, 0);
    return result;
}