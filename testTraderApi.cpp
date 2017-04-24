// testTraderApi.cpp : 定义控制台应用程序的入口点。
//
#include "./TraderAPI/ThostFtdcTraderApi.h"
#include "TraderSpi.h"

// UserApi对象
CThostFtdcTraderApi* pUserApi;

char  FRONT_ADDR[] = "tcp://180.168.146.187:10000";		// 前置地址
TThostFtdcBrokerIDType	BROKER_ID = "9999";				// 经纪公司代码
TThostFtdcInvestorIDType INVESTOR_ID = "00092";			// 注意输入你自己的simnow仿真投资者代码
TThostFtdcPasswordType  PASSWORD = "888888";			// 注意输入你自己的simnow仿真用户密码


TThostFtdcInstrumentIDType INSTRUMENT_ID = "rb1701";	// 合约代码 ，注意与时俱进改变合约ID,避免使用过时合约
TThostFtdcDirectionType	DIRECTION = THOST_FTDC_D_Sell;	// 买卖方向
TThostFtdcPriceType	LIMIT_PRICE = 2380;				// 价格

// 请求编号
int iRequestID = 0;

int main(void)
{

	// 初始化UserApi
	pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi();			// 创建UserApi
	CTraderSpi* pUserSpi = new CTraderSpi();
	pUserApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi);			// 注册事件类
	//pUserApi->SubscribePublicTopic(TERT_RESTART);					// 注册公有流
	//pUserApi->SubscribePrivateTopic(TERT_RESTART);					// 注册私有流
	pUserApi->RegisterFront(FRONT_ADDR);							// connect
	pUserApi->Init();

	pUserApi->Join();
//	pUserApi->Release();
        
        return 0;
}
