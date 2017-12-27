
#include <opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  
using namespace cv;  

//���ø���Ȥ����ROIʵ��ͼ�����  
bool ROI_AddImage()  
{
    //����ͼ��
    Mat srcImage = imread("image/lol_pa.jpg");
    Mat logoImage = imread("image/lol_logo2.jpg");   

    //ͼ��У��
    if ((srcImage.data == NULL) || (logoImage.data == NULL))
    {
        printf("Load Image Err!\r\n");

        //�ȴ���������
        waitKey(0);

        return -1;
    }

    //�趨ROI����(��Ȥ����)
    Mat imageROI = srcImage(Rect(10,10,logoImage.cols,logoImage.rows));  
    //Mat imageROI = srcImage(Range(250,250+logoImage.rows),Range(200,200+logoImage.cols));  

    //������ģ(�����ǻҶ�ͼ)
    Mat mask = imread("image/lol_logo2.jpg", CV_LOAD_IMAGE_GRAYSCALE);   

    //����ģ������ROI
    logoImage.copyTo(imageROI, mask);

    //��ʾ���
    namedWindow("<1>����ROIʵ��ͼ�����ʾ������");  
    imshow("<1>����ROIʵ��ͼ�����ʾ������",srcImage); 

}


//����ͼ���ϡ������Ի�ϲ���
bool LinearBlending()  
{
    //����ͼ��
    Mat srcImage = imread("image/mogu.jpg");
    Mat logoImage = imread("image/rain.jpg");   
    Mat dstImage;

    //ͼ��У��
    if ((srcImage.data == NULL) || (logoImage.data == NULL))
    {
        printf("Load Image Err!\r\n");
        waitKey(0);
        return -1;
    }

    //ͼ���ϼ�Ȩ����
    double alphaValue = 0.4;
    addWeighted(srcImage, alphaValue, logoImage, (1-alphaValue), 0.0, dstImage);  

    //��ʾ���ͼ
    namedWindow("<2>���Ի��ʾ�����ڡ�ԭͼ��", 1);  
    imshow("<2>���Ի��ʾ�����ڡ�ԭͼ��", srcImage );  

    namedWindow("<3>���Ի��ʾ�����ڡ�Ч��ͼ��", 1);  
    imshow("<3>���Ի��ʾ�����ڡ�Ч��ͼ��", dstImage );  

    return true;
}

bool ROI_LinearBlending() 
{
    //����ͼ��
    Mat srcImage = imread("image/lol_pa.jpg");
    Mat logoImage = imread("image/rain3.jpg");   

    //ͼ��У��
    if ((srcImage.data == NULL) || (logoImage.data == NULL))
    {
        return -1;
    }

    //�趨ROI����(��Ȥ����)
    Mat imageROI = srcImage(Rect(10,10,logoImage.cols,logoImage.rows));  

    //ͼ���ϼ�Ȩ����
    double alphaValue = 0.8;
    addWeighted(imageROI, alphaValue, logoImage, (1-alphaValue), 0.0, imageROI);  

    //��ʾ���
    namedWindow("<4>��������ͼ����ʾ������");  
    imshow("<4>��������ͼ����ʾ������",srcImage);  

    return true;  
}

bool ROI_LinearBlendingGammaTest(void)
{
    //����ͼ��
    Mat srcImage = imread("image/lol_pa.jpg");
    Mat RainImage = imread("image/rain3.jpg");

    //ͼ��У��
    if ((srcImage.data == NULL) || (RainImage.data == NULL))
    {
        return -1;
    }

    //�趨ROI����(��Ȥ����)
    //����θ�ԭͼ���
    Mat imageROI = srcImage(Rect(0,0,RainImage.cols,RainImage.rows));  

    //ͼ���ϼ�Ȩ����
    double alphaValue = 0.8;
    addWeighted(imageROI, alphaValue, RainImage, (1-alphaValue), 40, imageROI);  

    //��ʾ���
    namedWindow("<5>��������ͼ����Gamma���Դ���");  
    imshow("<5>��������ͼ����Gamma���Դ���",srcImage);  
}

int main(void)
{
    //ROI��ϲ���
    ROI_AddImage();

    //���Ի�ϲ�������
    LinearBlending();

    //���Ի�ϲ�������2
    ROI_LinearBlending();

    //���Ի�ϲ�������3
    ROI_LinearBlendingGammaTest();

    //�ȴ���������
    waitKey(0);

    return 0;
}



