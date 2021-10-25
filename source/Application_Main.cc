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
#include <getopt.h>

#include "FTFP_BERT.hh"
#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "CLHEP/Random/MTwistEngine.h"

#include "geometry.h"
#include "user_action_initialization.h"
#include "score_edeps.h"

//-----------------------------------------------------------------------------
void PrintOpt(char opt)
{
   std::cout << opt << std::endl;
}

//-----------------------------------------------------------------------------
void SetDimention(char m, char *n)
{
   std::cout << m << n << std::endl;
}

//-----------------------------------------------------------------------------
int main( int argc, char** argv )
{
   //define longopt
   const char* opt_string = "ht";

   const struct option longopts[] ={
   {  "help",     no_argument,          0,   'h'},
   {  "test",     required_argument,    0,   't'},
   {  "nx",       required_argument,    0,   'x'},
   {  "ny",       required_argument,    0,   'y'},
   {  "nz",       required_argument,    0,   'z'}
   };

   int longopt_index = 0;

   auto n = getopt_long(argc, argv, opt_string, longopts, &longopt_index);

   if( n == 'h'){
      std::cout << "Help Me" << std::endl;
   }

   // Set random Engine
   auto rand_mtwin = new CLHEP::MTwistEngine();
   G4Random::setTheEngine(rand_mtwin);
   G4Random::setTheSeed(142734);

   // Construct the default run manager
   auto runManager = new G4RunManager{};

   // Set up mandatory user initialization: Geometry
   runManager->SetUserInitialization( new Geometry{} );

   // Set up mandatory user initialization: Physics-List
   runManager->SetUserInitialization( new FTFP_BERT{} );

   // Set up user initialization: User Actions
   runManager->SetUserInitialization( new UserActionInitialization{} );

   // Initialize G4 kernel
   runManager->Initialize();

   // Create visualization environment
   auto visManager = new G4VisExecutive{};
   visManager->Initialize();

   // Start interactive session
   auto uiExec = new G4UIExecutive( argc, argv );

   //G4UImanager*  uiManager = G4UImanager::GetUIpointer();

   //controll visual
   //uiManager->ApplyCommand( "/control/execute GlobalSetup.mac" );

   uiExec->SessionStart();


   // Job termination
   delete visManager;
   delete runManager;

   return 0;
}
