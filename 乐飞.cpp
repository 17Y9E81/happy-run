#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int sprintf(char *str, const char *format, ...);
bool InsertClipboard(const char* pszData, const int nDataLen){
    if(::OpenClipboard(NULL))
	{
	        ::EmptyClipboard();
	        HGLOBAL clipbuffer;
	        char *buffer;
	        clipbuffer = ::GlobalAlloc(GMEM_DDESHARE, nDataLen+1);
	        buffer = (char *)::GlobalLock(clipbuffer);
	        strcpy(buffer, pszData);
	        ::GlobalUnlock(clipbuffer);
	        ::SetClipboardData(CF_TEXT, clipbuffer);
	        ::CloseClipboard();
	        return TRUE;
	    }
    return FALSE;
}
void PasteInfo()//���̲ٿ� 
{
	keybd_event(0x11, 0, 0, 0);// press ctrl
	keybd_event(0x41, 0, 0, 0); // press A
	Sleep(100);
	keybd_event(0x41, 0, 2, 0); //release A
	keybd_event(0x11, 0, 1, 0); //release ctrl
	keybd_event(0x11, 0, 0, 0);// press ctrl
	keybd_event(0x56, 0, 0, 0); // press v
	Sleep(100);
	keybd_event(0x56, 0, 2, 0); //release v
	keybd_event(0x11, 0, 2, 0); //release ctrl
	//keybd_event(0x10, 0, 0, 0);// press shift 
	Sleep(100);
	//keybd_event(0x10, 0, 2, 0);// release 
	
	keybd_event(VK_RETURN,0,0,0);
	keybd_event(VK_RETURN,0,KEYEVENTF_KEYUP,0);//\n 
}

void solve(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int z1,int z2)
{
	double a,b; 
	int x,y,y0,x0;
	int x5=x1,y5=y1;
	//x1=408712;y1=53682;
	//x2=409170;y2=57564;
	x=(x1-x2)/30;y=(y1-y2)/30;
	x0=x1;y0=y1;
	for(int i=1;i<=30;i++)
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		Sleep(100);//Ҫ����ĳЩӦ�õķ�Ӧʱ�� 
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
//		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
//		Sleep(100);//Ҫ����ĳЩӦ�õķ�Ӧʱ�� 
//		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);//˫��ѡ�� 
		Sleep(100);
		x0-=x;
		y0-=y;
		Sleep(1.5* 1000);//��Ҫ�ӳ�T�룬��5��ΪT����
		a=0.000001*x0+z1;
		b=0.000001*y0+z2;
		char str[80];
		 sprintf(str, "%lf,%lf", a,b);
		 puts(str);
		InsertClipboard(str,a);
		PasteInfo();
	}			
	x1=x0;y1=y0;
	x2=x3;y2=y3;
	x=(x1-x2)/20;y=(y1-y2)/20;
	x0=x1;y0=y1;
	for(int i=1;i<=20;i++)
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		Sleep(100);//Ҫ����ĳЩӦ�õķ�Ӧʱ�� 
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
		x0-=x;
		y0-=y;
		Sleep(1.5* 1000);//��Ҫ�ӳ�T�룬��5��ΪT����
		a=0.000001*x0+z1;
		b=0.000001*y0+z2;
		char str[80];
		 sprintf(str, "%lf,%lf", a,b);
		 puts(str);
		InsertClipboard(str,a);
		PasteInfo();
	}	
	x1=x0;y1=y0;
	x2=x4;y2=y4;
	x=(x2-x1)/20;y=(y1-y2)/20;	
	x0=x1;y0=y1;
	for(int i=1;i<=20;i++)
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		Sleep(100);//Ҫ����ĳЩӦ�õķ�Ӧʱ�� 
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
		x0+=x;
		y0-=y;
		Sleep(5 * 1000);//��Ҫ�ӳ�T�룬��5��ΪT����
		a=0.000001*x0+z1;
		b=0.000001*y0+z2;
		char str[80];
		 sprintf(str, "%lf,%lf", a,b);
		 puts(str);
		InsertClipboard(str,a);
		PasteInfo();
	}
	x1=x0;y1=y0;
	x2=x5;y2=y5;
	x=(x2-x1)/20;y=(y2-y1)/20;
	x0=x1;y0=y1;
	for(int i=1;i<=20;i++)
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		Sleep(100);//Ҫ����ĳЩӦ�õķ�Ӧʱ�� 
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
		x0+=x;
		y0+=y;
		Sleep(2.5 * 1000);//��Ҫ�ӳ�T�룬��5��ΪT����
		a=0.000001*x0+z1;
		b=0.000001*y0+z2;
		char str[80];
		 sprintf(str, "%lf,%lf", a,b);
		 puts(str);
		InsertClipboard(str,a);
		PasteInfo();
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	int x1,y1,x2,y2,x3,y3,x4,y4,z1,z2;
	cout<<"�����ĸ����֣�Ϊ�ĸ�x�����С�����6λ(ʡ��ǰ׺0������408712\n";
	cin>>x1>>x2>>x3>>x4; 
	cout<<"�����ĸ����֣�Ϊ�ĸ�y�����С�����6λ(ʡ��ǰ׺0������53682\n";
	cin>>y1>>y2>>y3>>y4; 
	cout<<"�����������֣�Ϊx��y�������������\n";
	cin>>z1>>z2;
	cout<<"��¼����ʮ�����֣��´�ֱ�Ӹ��ƾ��У��������ļ�����\n";
	int t=0;
	cout<<"������������1��ʮ����������У����������ģ�ⶨλ�������\n";
	cin>>t; 
	Sleep(10000);	
	while(t!=0)
	{
		solve(x1,y1,x2,y2,x3,y3,x4,y4,z1,z2) ;
	}
	
}

