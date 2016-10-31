#include "mual_ttree_analyzer.h"
#include "mual_ttree_analyzer.cpp"

int mual_ttree_analyzer_main()
{
    mual_ttree_analyzer analyzer("mc_DT-1100-111111_CMSSW_8_0_17_ideal_5M03.root");

    chamberPlots chamber14(0,4,14);
    chamberPlots chamber1(0,4,1);
    //std::vector<chamberPlots> v_histograms; 
    //v_histograms.push_back(chamberPlots(0,4,14));    
    //v_histograms.push_back(chamberPlots(0,4,1));    
    
//        analyzer.myTTree->GetEntry(100)
//        analyzer.fillChamberPlots(chamber14);
//        analyzer.myTTree->GetEntry(1000);
//        analyzer.fillChamberPlots(chamber14);
//        analyzer.myTTree->GetEntry(10000);
//        analyzer.fillChamberPlots(chamber14);
//        analyzer.myTTree->GetEntry(1000000000);
//        analyzer.fillChamberPlots(chamber14);
//        analyzer.myTTree->GetEntry(10000000000);
//        analyzer.fillChamberPlots(chamber14);
//        analyzer.myTTree->GetEntry(100000000000);
//        analyzer.fillChamberPlots(chamber14);
   for ( int i = 0; i<  1000; i++) //analyzer.nEntries; i++)
   //for ( int i = 0; analyzer.nEntries; i++)
   {
        std::cout << i << std::endl;
        analyzer.myTTree->GetEntry(i);
        //analyzer.fillHisto();
        analyzer.fillChamberPlots(chamber14);

   } 
    analyzer.drawHisto(chamber14);

    return 0;

}
