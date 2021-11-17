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
#include<iostream>
#include<vector>

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4PrimaryParticle.hh"
#include "G4PrimaryVertex.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

#include "primary_generator.h"
#include "score_edeps.h"

//------------------------------------------------------------------------------
  PencilbeamGenerator::PencilbeamGenerator()
{
}

//------------------------------------------------------------------------------
  PencilbeamGenerator::~PencilbeamGenerator()
{
}

//------------------------------------------------------------------------------
  void PencilbeamGenerator::GeneratePrimaries( G4Event* anEvent )
{
  //Get particle-talbe pointer
  G4ParticleTable* particle_table = G4ParticleTable::GetParticleTable();

  std::string aName = "e-";
  double momentam = 20.0 * MeV;

  auto ssd = 100. * cm;

  auto direc_x =  0.;
  auto direc_y =  0.;
  auto direc_z =  1.;

  auto surface_time = ssd / direc_z;

  auto x_surface = direc_x * surface_time;
  auto y_surface = direc_y * surface_time;

  //checke direction of pencil beam
  // auto score_edeps = ScoreEdeps::GetInstance();
  // score_edeps-> AddPoint(x_surface  ,y_surface );

  G4ThreeVector direction = {direc_x, direc_y, direc_z};

  G4ThreeVector momVec = momentam * direction;

  auto particle_code = particle_table-> FindParticle(aName);

  auto primary_particle = new G4PrimaryParticle{ particle_code,
                                            momVec.x(),
                                            momVec.y(),
                                            momVec.z()};

  double pos_x = 0. * cm;
  double pos_y = 0. * cm;
  double pos_z = -65. * cm;
  double time_zero = 0. * s;

  auto primary_vertex = new G4PrimaryVertex{pos_x, pos_y, pos_z, time_zero};

  primary_vertex-> SetPrimary(primary_particle);

  anEvent-> AddPrimaryVertex(primary_vertex);

}
