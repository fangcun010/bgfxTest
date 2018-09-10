#include <windows.h>
#include <bgfx/c99/bgfx.h>
#include <bgfx/c99/platform.h>

//=========================================================================
//常量
//=========================================================================

//窗口大小
#define					WND_W							800
#define					WND_H							600

//默认渲染器
#define					RENDER_TYPE						BGFX_RENDERER_TYPE_OPENGL

//=========================================================================
//全局变量
//=========================================================================
HINSTANCE g_hInstance;
HWND g_hMainWnd;

//=========================================================================
//子程式声明
//=========================================================================

void InitBgfx();//初始化Bgfx
void Update();//渲染函数

LRESULT APIENTRY MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
bool RegClass(WNDCLASS &wc);

//窗口消息处理
void OnCreate();

//=========================================================================
//函数名称：WinMain
//说明：主函数
//输入：
//输出：
//返回：
//备注：
//日期：2018-9-10
//修改记录：
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
		MessageBox(NULL, "注册窗口类失败！", "BgfxTest", MB_OK);
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
//函数名称：Update
//说明：渲染函数
//输入：
//输出：
//返回：
//备注：
//日期：2018-9-10
//修改记录：
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
//函数名称：RegClass
//说明：注册窗口类
//输入：
//输出：
//返回：
//备注：
//日期：2018-9-10
//修改记录：
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
//函数名称：MainWndProc
//说明：消息处理函数
//输入：
//输出：
//返回：
//备注：
//日期：2018-9-10
//修改记录：
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
//函数名称：InitBgfx
//说明：初始化Bgfx
//输入：
//输出：
//返回：
//备注：
//日期：2018-9-10
//修改记录：
//=========================================================================
void InitBgfx()
{
	//设置平台相关信息
	
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
//函数名称：OnCreate
//说明：窗口创建消息处理
//输入：
//输出：
//返回：
//备注：
//日期：2018-9-10
//修改记录：
//=========================================================================
void OnCreate()
{

}