#include <TROOT.h>
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TProfile.h"
#include "TTree.h"
#include <vector>
#include <TCanvas.h>
#include <iostream>

class chamberPlots
{
    public:
    int targetWheel;
    int targetStation;
    int targetSector;
    char prefix[128];
    TH1F * TH1F_res_x_test;
    chamberPlots(int l_targetWheel, int l_targetStation, int l_targetSector);
    void drawHisto();
};

//chamberPlots::chamberPlots(int l_targetWheel, int l_targetStation, int l_targetSector)
//{
//    targetWheel = l_targetWheel;
//    targetStation = l_targetStation;
//    targetSector = l_targetSector;
//
//    char prefix[128];
//    sprintf(prefix,"DT_%d_%d_%d_",l_targetWheel,l_targetStation,l_targetSector);
//    std::cout << prefix << std::endl;
////TH1F_res_x_test = new TH1F(prefix + "TH1F_res_x_test", "Test histo", 100, -10, 10);
//    TH1F_res_x_test = new TH1F(prefix , "res x test plot", 100, -10, 10);
//
//
//}

class mual_ttree_analyzer
{

public:
bool printTTree;
int nXbins; 
int minPt; 
int maxPt; 
int canvasWidth;
int canvasHeight;
int nEntries;
double resRange;

Bool_t is_plus;
Bool_t is_dt;
Bool_t select;

UChar_t station;
Char_t ring_wheel;
UChar_t sector;
Char_t q;

Float_t res_x;
Float_t res_y;
Float_t res_slope_x;
Float_t res_slope_y;
Float_t pos_x;
Float_t pos_y;
Float_t angle_x;
Float_t angle_y;
Float_t pz;
Float_t pt;

TCanvas * myCanvas;
TH1F * TH1F_res_x; 
TFile * myFile; 
TTree * myTTree;

std::string fileName;

//std::vector<chamberPlots> v_histograms;

    mual_ttree_analyzer(std::string l_fileName);
    void drawHisto();
    void fillHisto();
    void fillChamberPlots();
};

//mual_ttree_analyzer::mual_ttree_analyzer(std::string l_fileName)
//{
//
//    printTTree = false; //warning, prints a lot of stuff
//
//    Xbins = 100;
//    minPt = 25;
//    maxPt = 250;
//    canvasWidth = 600;
//    canvasHeight = 600;
//    resRange = 10;
//
//    fileName = l_fileName;
//    
//    myCanvas = new TCanvas("name", "title", canvasWidth, canvasHeight);
//    TH1F_res_x = new TH1F("res_x", "res x test plot", nXbins, -resRange, resRange);
//
//    myFile = new TFile(fileName.c_str());
//    std::cout << "\n --- Contents of myFile: ---" << std::endl;
//    myFile->ls();
//    std::cout << "\n";
//
//    myTTree = (TTree*)myFile->Get("mual_ttree");
//    nEntries = myTTree->GetEntries();
//
//    myTTree->SetBranchAddress("res_x",&res_x);
//
//    myTTree->SetBranchAddress("is_plus",&is_plus);
//    myTTree->SetBranchAddress("is_dt",&is_dt);
//    myTTree->SetBranchAddress("select",&select);
//
//    myTTree->SetBranchAddress("station",&station);
//    myTTree->SetBranchAddress("ring_wheel",&ring_wheel);
//    myTTree->SetBranchAddress("sector",&sector);
//    myTTree->SetBranchAddress("q",&q);
//
//    myTTree->SetBranchAddress("res_x",&res_x);
//    myTTree->SetBranchAddress("res_y",&res_y);
//    myTTree->SetBranchAddress("res_slope_x",&res_slope_x);
//    myTTree->SetBranchAddress("res_slope_y",&res_slope_y);
//    myTTree->SetBranchAddress("pos_x",&pos_x);
//    myTTree->SetBranchAddress("pos_y",&pos_y);
//    myTTree->SetBranchAddress("angle_x",&angle_x);
//    myTTree->SetBranchAddress("angle_y",&angle_y);
//    myTTree->SetBranchAddress("pz",&pz);
//    myTTree->SetBranchAddress("pt",&pt);
//
//}
