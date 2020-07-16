package com.harvey.yuv;

/**
 * Created by hanhui on 2019/11/18 0018 17:58
 */
public class YuvUtil {
    static {
        System.loadLibrary("yuv-util");
    }

    /**
     * NV21 数据转成I420数据
     *
     * @param input  输入的NV21数据
     * @param output 输入的I420数据
     * @param width  宽
     * @param height 高
     */
    public static native int NV21ToI420(byte[] input, byte[] output,
                                        int width, int height);

    /**
     * 旋转I420数据
     *
     * @param input    输入的I420数据
     * @param output   输入的I420数据
     * @param width    宽
     * @param height   高
     * @param rotation 旋转的角度 0，90，180和270
     */
    public static native int RotateI420(byte[] input, byte[] output,
                                        int width, int height, int rotation);

    /**
     * 缩放I420数据
     *
     * @param src        输入的I420数据
     * @param dst        输入的I420数据
     * @param width      原始的宽
     * @param height     原始的高
     * @param dst        输出数据
     * @param dst_width  输出的宽
     * @param dst_height 输出的高
     * @param mode       压缩模式。这里为0，1，2，3 速度由快到慢，质量由低到高，一般用0就好了，因为0的速度最快
     */
    public static native int ScaleI420(byte[] src, int width, int height,
                                       byte[] dst, int dst_width, int dst_height,
                                       int mode);

    /**
     * 镜像I420数据
     *
     * @param src    输入的I420数据
     * @param width  原始的宽
     * @param height 原始的高
     * @param dst    输入的I420数据
     */
    public static native int MirrorI420(byte[] src, int width, int height, byte[] dst);


    /**
     * yuv数据的裁剪操作
     *
     * @param src        原始I420数据
     * @param width      原始的宽
     * @param height     原始的高
     * @param dst        输出I420数据
     * @param dst_width  输出的宽
     * @param dst_height 输出的高
     * @param left       裁剪的x的开始位置，必须为偶数，否则显示会有问题
     * @param top        裁剪的y的开始位置，必须为偶数，否则显示会有问题
     **/
    public static native int CropI420(byte[] src, int width, int height,
                                      byte[] dst, int dst_width, int dst_height,
                                      int left, int top);

    /**
     * 将I420转化为NV21
     *
     * @param i420Src 原始I420数据
     * @param nv21Src 转化后的NV21数据
     * @param width   输出的宽
     * @param width   输出的高
     **/
    public static native int I420ToNV21(byte[] i420Src, byte[] nv21Src, int width, int height);

}
