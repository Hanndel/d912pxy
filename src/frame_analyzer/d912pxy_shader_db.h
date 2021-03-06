/*
MIT License

Copyright(c) 2018-2019 megai2

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#pragma once
#include "stdafx.h"

class d912pxy_shader_code_item : public d912pxy_noncom
{
public:
	d912pxy_shader_code_item(d912pxy_shader_uid mUID);
	~d912pxy_shader_code_item();
	
	d912pxy_shader_code GetCode();

private:
	d912pxy_shader_code code;

};

class d912pxy_shader_db : public d912pxy_noncom
{
public:
	d912pxy_shader_db(d912pxy_device* dev);
	~d912pxy_shader_db();

	d912pxy_shader_uid GetUID(DWORD* code, UINT32* len);

	//this must be called from PSO compile thread

	d912pxy_shader_code GetCode(d912pxy_shader_uid UID, d912pxy_shader* shader);
	d912pxy_shader_pair* GetPair(d912pxy_vshader* vs, d912pxy_pshader* ps);
	void DeletePair(UINT32 ha);

	void CleanUnusedPairs();

private:
	CRITICAL_SECTION treeAcCS;

	d912pxy_memtree* shaderCodes;
	d912pxy_memtree2* shaderPairs;
};

