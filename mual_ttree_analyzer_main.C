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
    
   for ( int i = 0; i < 10000; i++) //analyzer.nEntries; i++)
   {
        analyzer.myTTree->GetEntry(i);
        //analyzer.fillHisto();
        analyzer.fillChamberPlots(chamber14);

   } 
    analyzer.drawHisto(chamber14);

    return 0;

}
