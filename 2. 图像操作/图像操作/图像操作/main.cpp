//����������
#include <opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  
   
using namespace cv;  //OpenCV ���ƿռ�

int main()
{

//-----------------------------------������ͼ���ϡ�--------------------------------------  
//     ����������ͼ����  
//-----------------------------------------------------------------------------------------------  
    //����ͼ��
    Mat city= imread("city.jpg");  
    Mat timo= imread("timo.jpg");  

    //���������ʾ  
    namedWindow("��2��ԭ��ͼ");  
    imshow("��2��ԭ��ͼ",city);  
   
    namedWindow("��3��logoͼ");  
    imshow("��3��logoͼ",timo);  

    //����һ��Mat���ͣ����ڴ�ţ�ͼ���ROI  
    //ע: ����CV_LOAD_IMAGE_GRAYSCALE��ͼ��,������������в�������
    Mat imageROI;  
    imageROI=city(Rect(0,350,timo.cols,timo.rows)); 

    //��logo�ӵ�ԭͼ��  
    addWeighted(imageROI,0.5,timo,0.3,0.,imageROI);  

    //��ʾ���  
    namedWindow("��4��ԭ��+logoͼ");  
    imshow("��4��ԭ��+logoͼ",city);

    //���һ��jpgͼƬ������Ŀ¼��  
    imwrite("��Ī�ϳ�.jpg",city);  

    //�ȴ���������󴰿��Զ��ر�  
    waitKey(0);  
}

