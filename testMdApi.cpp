// testTraderApi.cpp : 定义控制台应用程序的入口点。
//

#include "./TraderAPI/ThostFtdcMdApi.h"
#include "MdSpi.h"

// UserApi对象
CThostFtdcMdApi* pUserApi;
//CThostFtdcTraderApi* TdApi;

// 配置参数
char FRONT_ADDR[] = "tcp://180.168.146.187:10010";		// 前置地址
char TradeFRONT_ADDR[] = "tcp://180.168.146.187:10000";
TThostFtdcBrokerIDType	BROKER_ID = "9999";				// 经纪公司代码
TThostFtdcInvestorIDType INVESTOR_ID = "00092";			// 投资者代码
TThostFtdcPasswordType  PASSWORD = "888888";			// 用户密码
char *ppInstrumentID[] = {"cu0907", "cu0909"};			// 行情订阅列表
int iInstrumentID = 2;									// 行情订阅数量

// 请求编号
int iRequestID = 0;

int main(void)
{
	// 初始化UserApi
	pUserApi = CThostFtdcMdApi::CreateFtdcMdApi();			// 创建UserApi
	CThostFtdcMdSpi* pUserSpi = new CMdSpi();
	
        pUserApi->RegisterSpi(pUserSpi);						// 注册事件类
	pUserApi->RegisterFront(TradeFRONT_ADDR);					// connect
	//pUserApi->SubscribePiblicTopic(THOST_TERT_RESUME);
        //pUserApi->SubscribePrivateTopic(THOST_TERT_RESUME);
        pUserApi->Init();
        pUserApi->Join();
//	pUserApi->Release();
        return 0;
}
