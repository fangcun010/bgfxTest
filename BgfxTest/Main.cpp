#include <windows.h>
#include <bgfx/c99/bgfx.h>
#include <bgfx/c99/platform.h>

//=========================================================================
//����
//=========================================================================

//���ڴ�С
#define					WND_W							800
#define					WND_H							600

//Ĭ����Ⱦ��
#define					RENDER_TYPE						BGFX_RENDERER_TYPE_OPENGL

//=========================================================================
//ȫ�ֱ���
//=========================================================================
HINSTANCE g_hInstance;
HWND g_hMainWnd;

//=========================================================================
//�ӳ�ʽ����
//=========================================================================

void InitBgfx();//��ʼ��Bgfx
void Update();//��Ⱦ����

LRESULT APIENTRY MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
bool RegClass(WNDCLASS &wc);

//������Ϣ����
void OnCreate();

//=========================================================================
//�������ƣ�WinMain
//˵����������
//���룺
//�����
//���أ�
//��ע��
//���ڣ�2018-9-10
//�޸ļ�¼��
//=========================================================================
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wc;
	HWND hWnd;
	MSG Msg;
	int x, y;
	
	g_hInstance = hInstance;

	ZeroMemory(&wc, sizeof(wc));
	if (!RegClass(wc))
	{
		MessageBox(NULL, "ע�ᴰ����ʧ�ܣ�", "BgfxTest", MB_OK);
		return 1;
	}

	x = (GetSystemMetrics(SM_CXSCREEN) - WND_W) / 2;
	y = (GetSystemMetrics(SM_CYSCREEN) - WND_H) / 2;

	hWnd = CreateWindow("BgfxTestWnd", "BgfxTest", WS_OVERLAPPEDWINDOW,
							x, y,
							WND_W, WND_H,
							NULL,
							NULL,
							hInstance,
							NULL);

	ShowWindow(hWnd, nCmdShow);
	g_hMainWnd = hWnd;
	InitBgfx();

	while (GetMessage(&Msg, NULL, NULL, NULL))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);

		Update();
	}

	return (int)Msg.wParam;
}

//=========================================================================
//�������ƣ�Update
//˵������Ⱦ����
//���룺
//�����
//���أ�
//��ע��
//���ڣ�2018-9-10
//�޸ļ�¼��
//=========================================================================
void Update()
{
	bgfx_set_view_rect(0, 0, 0, WND_W, WND_H);
	bgfx_touch(0);
	
	bgfx_dbg_text_clear(0, false);
	bgfx_dbg_text_printf(0, 0, 0xf, "Hello World!");
	
	bgfx_frame(false);
}


//=========================================================================
//�������ƣ�RegClass
//˵����ע�ᴰ����
//���룺
//�����
//���أ�
//��ע��
//���ڣ�2018-9-10
//�޸ļ�¼��
//=========================================================================
bool RegClass(WNDCLASS &wc)
{
	wc.lpszClassName = "BgfxTestWnd";
	wc.lpszMenuName = NULL;
	wc.hInstance = g_hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpfnWndProc = MainWndProc;
	wc.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;

	if (RegisterClass(&wc)) return true;
	else return false;
}

//=========================================================================
//�������ƣ�MainWndProc
//˵������Ϣ������
//���룺
//�����
//���أ�
//��ע��
//���ڣ�2018-9-10
//�޸ļ�¼��
//=========================================================================
LRESULT WINAPI MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int wmID;
	int wmEvent;
	
	switch (uMsg)
	{
	case WM_CREATE:
		OnCreate();
		break;
	case WM_COMMAND:
		break;
	case WM_LBUTTONDOWN:
		
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_MOUSEMOVE:
		break;
	case WM_KEYDOWN:
		break;
	case WM_PAINT:
		break;
	case WM_SIZE:
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	case WM_DESTROY:
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//=========================================================================
//�������ƣ�InitBgfx
//˵������ʼ��Bgfx
//���룺
//�����
//���أ�
//��ע��
//���ڣ�2018-9-10
//�޸ļ�¼��
//=========================================================================
void InitBgfx()
{
	//����ƽ̨�����Ϣ
	
	bgfx_platform_data_t platdata;
	
	ZeroMemory(&platdata, sizeof(platdata));
	platdata.nwh = g_hMainWnd;
	bgfx_set_platform_data(&platdata);

	bgfx_init_t init;

	bgfx_init_ctor(&init);
	bgfx_init(&init);

	bgfx_reset(WND_W, WND_H, BGFX_RESET_VSYNC, init.resolution.format);

	bgfx_set_debug(BGFX_DEBUG_TEXT);
	bgfx_set_view_clear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH,
		0x303030ff, 1.0f, 0);
}

//=========================================================================
//�������ƣ�OnCreate
//˵�������ڴ�����Ϣ����
//���룺
//�����
//���أ�
//��ע��
//���ڣ�2018-9-10
//�޸ļ�¼��
//=========================================================================
void OnCreate()
{

}