//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Geometry.cc
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Geometry.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4VPhysicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"
#include "G4Transform3D.hh"
#include "G4NistManager.hh"
#include "G4VisAttributes.hh"
#include "G4SystemOfUnits.hh"
#include "SensitiveVolume.hh"
#include "G4SDManager.hh"
//------------------------------------------------------------------------------
  Geometry::Geometry() {}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
  Geometry::~Geometry() {}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
  G4VPhysicalVolume* Geometry::Construct()
//------------------------------------------------------------------------------
{
// Get pointer to 'Material Manager'
   G4NistManager* materi_Man = G4NistManager::Instance();

// Define 'World Volume'
   // Define the shape of solid
   G4double leng_X_World = 100.0 * cm;         // X-full-length of world
   G4double leng_Y_World = 100.0 * cm;         // Y-full-length of world
   G4double leng_Z_World = 300.0 * cm;         // Z-full-length of world
   auto solid_World = new G4Box{ "Solid_World",
                         leng_X_World/2.0, leng_Y_World/2.0, leng_Z_World/2.0 };

   // Define logical volume
   G4Material* materi_World = materi_Man->FindOrBuildMaterial( "G4_AIR" );
   auto logVol_World = new G4LogicalVolume{ solid_World, materi_World,
                                            "LogVol_World" };
   logVol_World->SetVisAttributes ( G4VisAttributes::Invisible );

   // Placement of logical volume
   G4int copyNum_World = 0;               // Set ID number of world
   auto physVol_World  = new G4PVPlacement{ G4Transform3D(), "PhysVol_World",
                                        logVol_World, 0, false, copyNum_World };

// Define 'Pixel Detector' - Global Envelop
   // Define the shape of the global envelop
   G4double leng_X_PixEnvG = 30.5 * cm;     // X-full-length of pixel: global envelop
   G4double leng_Y_PixEnvG = 30.5 * cm;     // Y-full-length of pixel: global envelop
   G4double leng_Z_PixEnvG = 30.0 * cm;     // Z-full-length of pixel: global envelop
   auto solid_PixEnvG = new G4Box{ "Solid_PixEnvG", leng_X_PixEnvG / 2.0,
                                   leng_Y_PixEnvG / 2.0, leng_Z_PixEnvG / 2.0 };

   // Define logical volume of the global envelop
   G4Material* materi_PixEnvG = materi_Man->FindOrBuildMaterial( "G4_AIR" );
   auto logVol_PixEnvG = new G4LogicalVolume{ solid_PixEnvG, materi_PixEnvG,
                                              "LogVol_PixEnvG" };
   logVol_PixEnvG->SetVisAttributes ( G4VisAttributes::Invisible );

// Define 'Pixel Detector' - Local Envelop (divided the global envelop in Y-direction)
   // Define the shape of the local envelop
   G4int nDiv_Y = 5; //61                                 // Number of divisions in Y-direction
   G4double leng_X_PixEnvL = leng_X_PixEnvG;          // X-full-length of pixel: local envelop
   G4double leng_Y_PixEnvL = leng_Y_PixEnvG / nDiv_Y;   // Y-full-length of pixel: local envelop
   G4double leng_Z_PixEnvL = leng_Z_PixEnvG;          // Z-full-length of pixel: local envelop
   auto solid_PixEnvL = new G4Box{ "Solid_PixEnvL", leng_X_PixEnvL / 2.0,
                                   leng_Y_PixEnvL / 2.0, leng_Z_PixEnvL / 2.0 };

   // Define logical volume of the local envelop
   G4Material* materi_PixEnvL = materi_Man->FindOrBuildMaterial( "G4_WATER" );
   auto logVol_PixEnvL = new G4LogicalVolume{ solid_PixEnvL, materi_PixEnvL,
                                              "LogVol_PixEnvL" };

   // Placement of the local envelop to the global envelop using Replica
   new G4PVReplica{ "PhysVol_PixEnvL", logVol_PixEnvL, logVol_PixEnvG, kYAxis,
                    nDiv_Y, leng_Y_PixEnvL };

// Define 'Pixel Detector' - Pixel Element (divided the local envelop in X-direction)
   // Define the shape of the pixel element
   G4int nDiv_X = 5; //61                                  // Number of divisions in X-direction
   G4double leng_X_PixElmt = leng_X_PixEnvG / nDiv_X;    // X-full-length of pixel: pixel element
   G4double leng_Y_PixElmt = leng_Y_PixEnvG / nDiv_Y;    // Y-full-length of pixel: pixel element
   G4double leng_Z_PixElmt = leng_Z_PixEnvG;           // Z-full-length of pixel: pixel element
   auto solid_PixElmt = new G4Box{ "Solid_PixElmt", leng_X_PixElmt / 2.0,
                                   leng_Y_PixElmt / 2.0, leng_Z_PixElmt / 2.0 };

   // Define logical volume of the pixel element
   G4Material* materi_PixElmt = materi_Man->FindOrBuildMaterial( "G4_WATER" );
   auto logVol_PixElmt = new G4LogicalVolume{ solid_PixElmt, materi_PixElmt,
                                              "LogVol_PixElmt" };

   // Placement of pixel elements to the local envelop using Replica
   new G4PVReplica{ "PhysVol_PixElmt", logVol_PixElmt, logVol_PixEnvL, kXAxis,
                    nDiv_X, leng_X_PixElmt };

// Define 'Pixel Detector' - Pixel Element (divided the local envelop in Z-direction)
   // Define the shape of the pixel element
   G4int nDiv_Z = 15; //150                                 // Number of divisions in Z-direction
   G4double leng_X_PixElmts = leng_X_PixEnvG / nDiv_X;    // X-full-length of pixel: pixel element
   G4double leng_Y_PixElmts = leng_Y_PixEnvG / nDiv_Y;    // Y-full-length of pixel: pixel element
   G4double leng_Z_PixElmts = leng_Z_PixEnvG / nDiv_Z;    // Z-full-length of pixel: pixel element
   auto solid_PixElmts = new G4Box{ "Solid_PixElmts", leng_X_PixElmts / 2.0,
                                   leng_Y_PixElmts / 2.0, leng_Z_PixElmts / 2.0 };

   // Define logical volume of the pixel element
   G4Material* materi_PixElmts = materi_Man->FindOrBuildMaterial( "G4_WATER" );
   auto logVol_PixElmts = new G4LogicalVolume{ solid_PixElmts, materi_PixElmts,
                                              "LogVol_PixElmts" };

   // Placement of pixel elements to the local envelop using Replica
   new G4PVReplica{ "PhysVol_PixElmts", logVol_PixElmts, logVol_PixElmt, kZAxis,
                    nDiv_Z, leng_Z_PixElmts };

// Placement of the 'Pixel Detector' to the world: Put the 'global envelop'
   G4double pos_X_LogV_PixEnvG = 0.0 * cm;       // X-location LogV_PixEnvG
   G4double pos_Y_LogV_PixEnvG = 0.0 * cm;       // Y-location LogV_PixEnvG
   G4double pos_Z_LogV_PixEnvG = 115.5 * cm;       // Z-location LogV_PixEnvG
   auto threeVect_LogV_PixEnvG = G4ThreeVector{ pos_X_LogV_PixEnvG,
                                       pos_Y_LogV_PixEnvG, pos_Z_LogV_PixEnvG };
   auto rotMtrx_LogV_PixEnvG = G4RotationMatrix{};
   auto trans3D_LogV_PixEnvG = G4Transform3D{ rotMtrx_LogV_PixEnvG, threeVect_LogV_PixEnvG };

   G4int copyNum_LogV_PixEnvG = 1000;                // Set ID number of LogV_PixEnvG
   new G4PVPlacement{ trans3D_LogV_PixEnvG, "PhysVol_PixEnvG", logVol_PixEnvG, physVol_World,
                      false, copyNum_LogV_PixEnvG };

// Sensitive volume
    auto aSV = new SensitiveVolume("SensitiveVolume");
    logVol_PixElmts->SetSensitiveDetector(aSV);         // Add sensitivity to the logical volume
    auto SDman = G4SDManager::GetSDMpointer();
    SDman->AddNewDetector(aSV);

// Return the physical world
   return physVol_World;
}
               