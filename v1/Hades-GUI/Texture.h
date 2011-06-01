/*
Copyright (c) 2010 Jan Miguel Garcia (bobbysing)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#pragma once

// C++ Standard Library
#include <string>

// Windows API
#include <atlbase.h>

// DirectX
#include <d3d9.h>
#include <d3dx9.h>

namespace Hades
{
  namespace GUI
  {
    class Texture
    {
    public:
      Texture(ID3DXSprite* pSprite, std::string const& Path);

      void SetSprite(ID3DXSprite * pSprite);

      IDirect3DTexture9* GetTexture() const;

      void SetAlpha(BYTE bAlpha);

      void Draw(class Pos cpPos, int iWidth, int iHeight);

    private:
      CComPtr<IDirect3DTexture9> m_pTexture;
      D3DSURFACE_DESC m_TexDesc;
      ID3DXSprite* m_pSprite;
      IDirect3DDevice9* m_pDevice;
      BYTE m_Alpha;
    };
  }
}