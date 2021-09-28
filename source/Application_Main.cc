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

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Geant4 Application: Tutorial course for Hep/Medicine Users
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Geometry.hh"
#include "UserActionInitialization.hh"

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "FTFP_BERT.hh"

//-------------------------------------------------------------------------------
  int main( int argc, char** argv )
//-------------------------------------------------------------------------------
{
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

// Get UI (User Interface) manager
//   G4UImanager* uiManager = G4UImanager::GetUIpointer();

// Switch batch or interactive mode
//   if ( argc == 1 ) {  // Interactive mode - no command argument
//     auto uiExec = new G4UIExecutive{ argc, argv };
//     uiExec->SessionStart();
//     delete uiExec;
//   } else {            // Batch mode - 1st command argument is a macro-filename
//     G4String macroName = argv[1];
//     uiManager->ApplyCommand( "/control/execute " + macroName );
//   }

// Start interactive session
   auto uiExec = new G4UIExecutive( argc, argv );
   G4UImanager*  uiManager = G4UImanager::GetUIpointer();

   //controll visual 
   uiManager->ApplyCommand( "/control/execute GlobalSetup.mac" );

   uiExec->SessionStart();

// Job termination
   delete visManager;
   delete runManager;

   return 0;
}
