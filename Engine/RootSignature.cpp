#include "pch.h"
#include "RootSignature.h"

void RootSignature::Init(ComPtr<ID3D12Device> device)
{
	CD3DX12_ROOT_PARAMETER param[2];
	param[0].InitAsConstantBufferView(0); // 0번 -> b0 -> CBV 
	param[1].InitAsConstantBufferView(1); // 1번 -> b1 -> CBV

	D3D12_ROOT_SIGNATURE_DESC sigDesc = CD3DX12_ROOT_SIGNATURE_DESC(2, param);
	sigDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT; // 입력 조립기 단계

	ComPtr<ID3DBlob> blobSignature;
	ComPtr<ID3DBlob> blobError;
	::D3D12SerializeRootSignature(&sigDesc, D3D_ROOT_SIGNATURE_VERSION_1, &blobSignature, &blobError);
	device->CreateRootSignature(0, blobSignature->GetBufferPointer(), blobSignature->GetBufferSize(), IID_PPV_ARGS(&_signature));
}