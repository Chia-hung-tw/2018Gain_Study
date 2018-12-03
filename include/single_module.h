#ifndef single_module_h
#define single_module_h

#include "setup_config.h"
#include "MakePlots.h"
#include "TTree.h"
#include "TROOT.h"
#include "TH2Poly.h"
#include "TApplication.h"
#include "TChain.h"
#include <string>
#include <vector>

using namespace std;

class single_module{
 public:
  single_module( TChain *chain, string filename );
  ~single_module();
    
  //member
  string fname;
  string dirpath;
  string inj_CH_str;
  bool   inj_sweep;
  vector<int> inj_CH;
  int    inj_event;

  void Tprofile_Maker();

  
 private:
  
  TTree        *T_Rawhit;
  int          nevents;

  // Mainframe functions
  void Prerequisite();
  void Init();
  void Read_yaml(string yaml);
  void Setname();
  
  //member
  string moduleID_str;
  string labelID ;
  string filepath;

  
  ///////////////////////////////
  // Declaration of leaf types //
  ///////////////////////////////

   Int_t           eventID;
   vector<int>     *skirocID;
   vector<int>     *boardID;
   vector<int>     *channelID;
   vector<float>   *HighGainADC;
   vector<float>   *HighGainTmax;
   vector<float>   *HighGainChi2;
   vector<float>   *HighGainErrorADC;
   vector<float>   *HighGainErrorTmax;
   vector<int>     *HighGainStatus;
   vector<int>     *HighGainNCalls;
   vector<float>   *LowGainADC;
   vector<float>   *LowGainTmax;
   vector<float>   *LowGainChi2;
   vector<float>   *LowGainErrorADC;
   vector<float>   *LowGainErrorTmax;
   vector<int>     *LowGainStatus;
   vector<int>     *LowGainNCalls;
   vector<int>     *TotSlow;
   vector<int>     *ToaRise;
   vector<int>     *ToaFall;

  
};

#endif
