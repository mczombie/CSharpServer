#pragma once

#include "mczd3d11.h"

namespace mczd3d {

class CDevice
	: public IDevice
{
public:
	CDevice(void);
	~CDevice(void);

public:
	bool	Init(const INIT_INFO& info);
	void	Exit();

public:
	void	ClearMainRt(const mcz::vector4& vColor) override;
	bool	Flip() override;
	IVertexTypeMgr*	GetVertexTypeMgr() override;

public:
	ID3D11Device*	Get3DDevice() const;

private:
	bool	CreateMainRT();
	void	SetupViewPort(const INIT_INFO& info);

private:
	ID3D11Device*			m_p3dDevice;
	IDXGISwapChain*			m_pSwapChain;
	ID3D11DeviceContext*	m_pImmediateContext;
	ID3D11RenderTargetView*	m_pMainRtView;
};


CDevice* GetRealDevice();

}