#ifndef AliEbyEHigherMomentsEffContTask_cxx
#define AliEbyEHigherMomentsEffContTask_cxx

//=========================================================================//
//                                                                         //
//           Analysis Task for Net-Charge Higher Moment Analysis           //
//              Author: Satyajit Jena || Nirbhay K. Behera                 //
//                      sjena@cern.ch || nbehera@cern.ch                   //
//                               V0.0 23/08/2012                           //
//                                                                         //
//=========================================================================//


class TH1D;
class TH2D;
class THnSparse;
class AliPIDResponse;
class TString;
class AliAODEvent;
class AliPIDResponse;
class TList;

#include "TParticle.h"
#include "AliAnalysisTaskSE.h"

class AliEbyEHigherMomentsEffContTask: public AliAnalysisTaskSE {
 public:
  AliEbyEHigherMomentsEffContTask( const char *name = "HigherMomentAnalysis");
  virtual ~AliEbyEHigherMomentsEffContTask();

  virtual void    UserCreateOutputObjects();
  virtual void    UserExec(Option_t *option);
  virtual void    doAODEvent();
  virtual void    doMCAODEvent();
  virtual Bool_t  ProperVertex();
  virtual void    CheckContTrackAOD(Int_t label, Float_t sign, Int_t idxTrack);
  virtual void    FillEffSparse();
  virtual void    Terminate(Option_t *);

  void SetVertexDiamond(Double_t vx, Double_t vy, Double_t vz) {fVxMax = vx;fVyMax = vy; fVzMax = vz;}
  void SetCentralityEstimator(const char* centralityEstimator) { fCentralityEstimator = centralityEstimator;}
  void SetAnalysisType(const char* analysisType) {fAnalysisType = analysisType;}
  void SetDCA(Double_t xy, Double_t z) { fDCAxy = xy; fDCAz = z; }
  void SetPtRange(Double_t ptl, Double_t pth){fPtLowerLimit = ptl; fPtHigherLimit = pth;}
  void SetEta(Double_t eta){fEtaLowerLimit= -1*eta; fEtaHigherLimit= eta;}
  void SetRapidityCut(Double_t rapidity){ fRapidityCut = rapidity;}
  void SetNSigmaCut(Double_t nsigma){ fNSigmaCut = nsigma;}
  void SetParticleSpecies(AliPID::EParticleType pid) {fParticleSpecies = pid;}
  void SetTPCNclus(Int_t nclus) { fTPCNClus = nclus;}
  void SetChi2PerNDF( Double_t chi2ndf ) { fChi2perNDF = chi2ndf;}
  void SetAODtrackCutBit(Int_t bit){ fAODtrackCutBit = bit;}
  void SetUsePid( Bool_t usepid ){ fUsePid = usepid;}
  void SetContaMinationCheck( Bool_t checkCont ){ fCheckCont = checkCont;}
  void SetEfficencyJob( Bool_t efficiency ){ fEff = efficiency;}
  void SetKinematicsCutsAOD(Double_t ptl, Double_t pth, Double_t eta){
    fPtLowerLimit = ptl;
    fPtHigherLimit = pth;
    fEtaLowerLimit = -1*eta;
    fEtaHigherLimit = eta;
    
  }
 
 
 private:

  TList *fListOfHistosQA;
  TList *fListOfHistos;
  AliAODEvent           *fAOD;
  TClonesArray          *fArrayMC;
  AliPIDResponse	*fPIDResponse;
  AliPID::EParticleType fParticleSpecies;
  
  TString          fAnalysisType;          // "MC", "ESD", "AOD"
  TString          fCentralityEstimator;   // "V0M","TRK","TKL","ZDC","FMD"

  Int_t fCentrality;
  Double_t fVxMax;               //vxmax
  Double_t fVyMax;//vymax
  Double_t fVzMax;//vzmax

  Double_t fDCAxy;
  Double_t fDCAz;
  Double_t fPtLowerLimit;
  Double_t fPtHigherLimit;
  Double_t fEtaLowerLimit;
  Double_t fEtaHigherLimit;
  Double_t fRapidityCut;
  Double_t fNSigmaCut;
  Int_t fTPCNClus;
  Double_t fChi2perNDF;
  Int_t fAODtrackCutBit;//track cut bit from track selection (only used for AODs)
  Int_t **fLabel;
  Bool_t fUsePid;
  Bool_t fCheckCont;
  Bool_t fEff;
  TH1D *fEventCounter;
  
  TH1D *fHistQA[13];
  TH2D *fHistDCA;
  TH2D *fTPCSig;
  TH2D *fTPCSigA;
  
  THnSparse *fTHnCentNplusNminusCh;
  THnSparse *fTHnCentNplusNminus;
  THnSparse *fTHnCentNplusNminusPid[5];
  THnSparse *fTHnEff;
  THnSparse *fTHnCont;
  
  AliEbyEHigherMomentsEffContTask(const AliEbyEHigherMomentsEffContTask&);
  AliEbyEHigherMomentsEffContTask& operator = (const AliEbyEHigherMomentsEffContTask&);//Not implimented..
  ClassDef(AliEbyEHigherMomentsEffContTask, 1);
  
};

#endif

 
