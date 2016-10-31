#include "mual_ttree_analyzer.h"

chamberPlots::chamberPlots(int l_targetWheel, int l_targetStation, int l_targetSector)
{
    targetWheel = l_targetWheel;
    targetStation = l_targetStation;
    targetSector = l_targetSector;

    char prefix[128];
    sprintf(prefix,"DT_%d_%d_%d_",l_targetWheel,l_targetStation,l_targetSector);
    std::cout << prefix << std::endl;
//TH1F_res_x_test = new TH1F(prefix + "TH1F_res_x_test", "Test histo", 100, -10, 10);

    sprintf(prefix,"DT_%d_%d_%d_%s",l_targetWheel,l_targetStation,l_targetSector, "TH1F_res_x");
    TH1F_res_x_test = new TH1F(prefix, "x Residual; x Residual (cm);counts", 100, -10, 10);

    sprintf(prefix,"DT_%d_%d_%d_%s",l_targetWheel,l_targetStation,l_targetSector, "TProfile_res_x_track_x");
    TProfile_res_x_track_x = new TProfile(prefix, "x Residual vs.Track x Position;x Residual (cm);x Track (cm)", 100, -225, 225, -10,10);

}
void chamberPlots::drawHisto()
{
    
}


mual_ttree_analyzer::mual_ttree_analyzer(std::string l_fileName)
{

    printTTree = false; //warning, prints a lot of stuff

    nXbins = 100;
    minPt = 25;
    maxPt = 250;
    canvasWidth = 600;
    canvasHeight = 600;
    resRange = 10;

    fileName = l_fileName;

    myCanvas = new TCanvas("name", "title", canvasWidth, canvasHeight);
    TH1F_res_x = new TH1F("res_x", "res x test plot", nXbins, -resRange, resRange);

    myFile = new TFile(fileName.c_str());
    std::cout << "\n --- Contents of myFile: ---" << std::endl;
    myFile->ls();
    std::cout << "\n";

    myTTree = (TTree*)myFile->Get("mual_ttree");
    nEntries = myTTree->GetEntries();

    //myTTree->SetBranchAddress("res_x",&res_x);

    myTTree->SetBranchAddress("is_plus",&is_plus);
    myTTree->SetBranchAddress("is_dt",&is_dt);
    myTTree->SetBranchAddress("select",&select);

    myTTree->SetBranchAddress("station",&station);
    myTTree->SetBranchAddress("ring_wheel",&ring_wheel);
    myTTree->SetBranchAddress("sector",&sector);
    myTTree->SetBranchAddress("q",&q);

    myTTree->SetBranchAddress("res_x",&res_x);
    myTTree->SetBranchAddress("res_y",&res_y);
    myTTree->SetBranchAddress("res_slope_x",&res_slope_x);
    myTTree->SetBranchAddress("res_slope_y",&res_slope_y);
    myTTree->SetBranchAddress("pos_x",&pos_x);
    myTTree->SetBranchAddress("pos_y",&pos_y);
    myTTree->SetBranchAddress("angle_x",&angle_x);
    myTTree->SetBranchAddress("angle_y",&angle_y);
    myTTree->SetBranchAddress("pz",&pz);
    myTTree->SetBranchAddress("pt",&pt);

}



void mual_ttree_analyzer::fillHisto()
{
        TH1F_res_x->Fill(res_x);
}


void mual_ttree_analyzer::drawHisto()
{
    sprintf(prefix,"DT_%d_%d_%d",targetWheel,targetStation,targetSector);
    int status;
    status = mkdir("./DT_plots/"+prefix+"/", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    TH1F_res_x->Draw();
    myCanvas->SaveAs(prefix + "TH1F_res_x.png");
}

void mual_ttree_analyzer::drawHisto(chamberPlots l_chamber)
{
    
    char prefix[128];
    sprintf(prefix,"./DT_plots/DT_%d_%d_%d/",l_chamber.targetWheel,l_chamber.targetStation,l_chamber.targetSector);
    int status;
    //status = mkdir("./DT_plots/"+prefix+"/", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    
    //status = mkdir(prefix, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    l_chamber.TH1F_res_x_test->Draw();
    sprintf(prefix,"./DT_plots/DT_%d_%d_%d/TH1F_res_x.png",l_chamber.targetWheel,l_chamber.targetStation,l_chamber.targetSector);
    myCanvas->SaveAs(prefix);

    l_chamber.TProfile_res_x_track_x->Draw();
    sprintf(prefix,"./DT_plots/DT_%d_%d_%d/%s",l_chamber.targetWheel,l_chamber.targetStation,l_chamber.targetSector, "TProfile_res_x_track_x.png");
    myCanvas->SaveAs(prefix);

}


void mual_ttree_analyzer::fillChamberPlots(chamberPlots l_chamber)

{
//    if( (UChar_t)12 == sector){
//        std::cout << "12" << std::endl;
//    }
//    int test = (int)sector;
//    std::cout << test  << std::endl;
    //if((int)ring_wheel==l_chamber.targetWheel&&(int)station==l_chamber.targetStation&&(int)sector==l_chamber.targetSector)
    //{
        l_chamber.TH1F_res_x_test->Fill(res_x);
        track_x = res_x + pos_x;
        //std::cout << track_x << std::endl;
        l_chamber.TProfile_res_x_track_x->Fill(track_x,res_x);
        //std::cout << "clear" <<std::endl;
    //}
}



