#ifndef ALIBALANCETRIGGERED_H
#define ALIBALANCETRIGGERED_H
/*  See cxx source for full Copyright notice */


//-------------------------------------------------------------------------
//                          Class AliBalanceTriggered
//   This is the class for the Balance Function analysis
//
//    Origin: Panos Christakoglou, UOA-CERN, Panos.Christakoglou@cern.ch
//    Modified: Michael Weber, m.weber@cern.ch
//-------------------------------------------------------------------------

#include <TObject.h>
#include "TString.h"
#include  "AliTHn.h" // cannot forward declare 

class TGraphErrors;
class TH1D;

const Int_t kTrackVarsSingle = 4;       // track variables in histogram (eta, phi, pTtrig, centrality)
const Int_t kTrackVarsPair   = 5;       // track variables in histogram (dEta, dPhi, pT, pTtrig, centrality)

class AliBalanceTriggered : public TObject {
 public:

  AliBalanceTriggered();
  AliBalanceTriggered(const AliBalanceTriggered& balance);
  ~AliBalanceTriggered();
  
  // analysis setters
  void SetAnalysisLevel(const char* analysisLevel) {
    fAnalysisLevel = analysisLevel;}

  // analysis getters
  const char* GetAnalysisLevel() {return fAnalysisLevel.Data();}

  // initialize histograms
  void InitHistograms(void);

  // histogram setters
  void SetHistNp(AliTHn *gHist)  { fHistP  = gHist;}
  void SetHistNn(AliTHn *gHist)  { fHistN  = gHist;}
  void SetHistNpn(AliTHn *gHist) { fHistPN = gHist;}
  void SetHistNnp(AliTHn *gHist) { fHistNP = gHist;}
  void SetHistNpp(AliTHn *gHist) { fHistPP = gHist;}
  void SetHistNnn(AliTHn *gHist) { fHistNN = gHist;}
 
  // histogram getters
  AliTHn *GetHistNp() { return fHistP;}
  AliTHn *GetHistNn() { return fHistN;}
  AliTHn *GetHistNpn() { return fHistPN;}
  AliTHn *GetHistNnp() { return fHistNP;}
  AliTHn *GetHistNpp() { return fHistPP;}
  AliTHn *GetHistNnn() { return fHistNN;}

  // Fill balance function histograms
  void FillBalance(Float_t fCentrality,TObjArray* particles,TObjArray* particlesMixed);
 
  // Get the balance function histogram 
  TH1D *GetBalanceFunctionHistogram1D(Int_t var, Double_t pTMinTrigger, Double_t pTMaxTrigger, Double_t pTMin, Double_t pTMax, Double_t centrMin, Double_t centrMax, Double_t etaGap = -1);

  // Get the balance function histogram (2D) 
  TH2D *GetBalanceFunctionHistogram2D(Int_t var1, Int_t var2, Double_t pTMinTrigger, Double_t pTMaxTrigger, Double_t pTMin, Double_t pTMax, Double_t centrMin, Double_t centrMax);

  // Get 1D histogram
  TH1D* GetHistogram1D(Int_t histo, Int_t var, Double_t pTMinTrigger, Double_t pTMaxTrigger, Double_t pTMin, Double_t pTMax, Double_t centrMin, Double_t centrMax, Double_t etaGap = -1);

  // Get 2D histogram
  TH2D* GetHistogram2D(Int_t histo, Int_t var1, Int_t var2, Double_t pTMinTrigger, Double_t pTMaxTrigger, Double_t pTMin, Double_t pTMax, Double_t centrMin, Double_t centrMax);

 private:
  TString fAnalysisLevel; // ESD, AOD or MC

  AliTHn *fHistP;  //N+
  AliTHn *fHistN;  //N-
  AliTHn *fHistPN; //N+-
  AliTHn *fHistNP; //N-+
  AliTHn *fHistPP; //N++
  AliTHn *fHistNN; //N--

  AliBalanceTriggered & operator=(const AliBalanceTriggered & ) {return *this;}

  ClassDef(AliBalanceTriggered, 1)
};

#endif
