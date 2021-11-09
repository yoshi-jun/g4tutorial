/*==============================================================================
  BSD 2-Clause License
  Copyright (c) 2021 Junichi Yoshida
  All rights reserved.
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  1. Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
  OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
==============================================================================*/
#include <iostream>

#include "beam_chooser.h"

//----------------------------------------------------------------------------
BeamChooser::BeamChooser()
{
 beam_flag_ = 0;
}

//-----------------------------------------------------------------------------
BeamChooser* BeamChooser::GetInstance()
{
  static BeamChooser the_chooser;

  return &the_chooser;
}
//-----------------------------------------------------------------------------
void BeamChooser::SetChooser(int val)
{
  beam_flag_ = val;
}

//-----------------------------------------------------------------------------
bool BeamChooser::GetChoosed() const
{
  return beam_flag_ == 1;
}

//-----------------------------------------------------------------------------
void BeamChooser::SetSaveCh(int val)
{
  save_flag_ = val;
}

//-----------------------------------------------------------------------------
bool BeamChooser::GetSaveCh() const
{
  return save_flag_ == 1;
}
