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

#include "G4TouchableHistory.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4ParticleDefinition.hh"
#include "G4HCofThisEvent.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

#include "sensitive_volume.h"
//------------------------------------------------------------------------------
  SensitiveVolume::SensitiveVolume(G4String name)
  : G4VSensitiveDetector(name)
{

}

//------------------------------------------------------------------------------
  SensitiveVolume::~SensitiveVolume()
{

}

//------------------------------------------------------------------------------
  void SensitiveVolume::Initialize(G4HCofThisEvent*)
{
  sum_eDep = 0.;
  sum_stepLength =0.;
}

//------------------------------------------------------------------------------
  void SensitiveVolume::EndOfEvent(G4HCofThisEvent*)
{
  auto dose_score = ScoreEdeps::GetInstance();

  dose_score-> CountEvent();
  auto events = dose_score-> GetEventTimes();

  if ( events % 10000 == 0){
    std::cout << "================================================" << std::endl
              << "              The end of event      "
              << events << std::endl
              << "================================================" << std::endl
              << std::endl;
  }

}

//------------------------------------------------------------------------------
  G4bool SensitiveVolume::ProcessHits(G4Step* aStep, G4TouchableHistory*)
{
  auto edep = aStep-> GetTotalEnergyDeposit();

  //Get boxcell number (copyNum)

  auto copyNum_z = aStep-> GetPreStepPoint()-> GetTouchableHandle()
                      -> GetCopyNumber(0);

  auto copyNum_y = aStep-> GetPreStepPoint()-> GetTouchableHandle()
                      -> GetCopyNumber(1);

  auto copyNum_x = aStep-> GetPreStepPoint()-> GetTouchableHandle()
                      -> GetCopyNumber(2);

  //Get position before collegeon
  auto pre_step_pt = aStep-> GetPreStepPoint()-> GetPosition();

  //Score pre-step-point and Number of box-cell
  auto dose_score = ScoreEdeps::GetInstance();


  dose_score-> AddDose(copyNum_x, copyNum_y, copyNum_z, edep);

  dose_score->AddTotallEDeps(edep);

  if (aStep-> IsFirstStepInVolume()) {
    if (copyNum_z == 0){
      if (aStep-> GetTrack()-> GetParentID() == 0){
        dose_score-> AddPoint(pre_step_pt[0] / cm,
                              pre_step_pt[1] / cm,
                              pre_step_pt[2] / cm);

      }
    }
  }


  return true;
}
