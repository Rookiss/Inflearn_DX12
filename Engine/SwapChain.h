#pragma once


// 교환 사슬
// [외주 과정]
// - 현재 게임 세상에 있는 상황을 묘사
// - 어떤 공식으로 어떻게 계산할지 던져줌
// - GPU가 열심히 계산 (외주)
// - 결과물 받아서 화면에 그려준다

// [외주 결과물]을 어디에 받지?
// - 어떤 종이(Buffer)에 그려서 건내달라고 부탁해보자
// - 특수 종이를 만들어서 -> 처음에 건내주고 -> 결과물을 해당 종이에 받는다 OK
// - 우리 화면에 특수 종이(외주 결과물) 출력해준다

// [?]
// - 그런데 화면에 현재 결과물 출력하는 와중에, 다음 화면도 외주를 맡겨야 함
// - 현재 화면 결과물은 이미 화면 출력에 사용중
// - 특수 종이를 2개 만들어서, 하나는 현재 화면을 그려주고, 하나는 외주 맡기고...
// - Double Buffering!

// - [0] [1]
// 현재 화면 [0]  <-> GPU 작업중 [1] BackBuffer

class SwapChain
{
public:
	void Init(const WindowInfo& info, ComPtr<IDXGIFactory> dxgi, ComPtr<ID3D12CommandQueue> cmdQueue);
	void Present();
	void SwapIndex();

	ComPtr<IDXGISwapChain> GetSwapChain() { return _swapChain; }
	ComPtr<ID3D12Resource> GetRenderTarget(int32 index) { return _renderTargets[index]; }

	uint32 GetCurrentBackBufferIndex() { return _backBufferIndex; }
	ComPtr<ID3D12Resource> GetCurrentBackBufferResource() { return _renderTargets[_backBufferIndex]; }

private:
	ComPtr<IDXGISwapChain>	_swapChain;
	ComPtr<ID3D12Resource>	_renderTargets[SWAP_CHAIN_BUFFER_COUNT];
	uint32					_backBufferIndex = 0;
};

