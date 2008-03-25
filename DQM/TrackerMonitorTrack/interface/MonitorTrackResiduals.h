#ifndef MonitorTrackResiduals_H
#define MonitorTrackResiduals_H

// -*- C++ -*-
//
// Package:    TrackerMonitorTrack
// Class:      MonitorTrackResiduals
// 
/**\class MonitorTrackResiduals MonitorTrackResiduals.h DQM/TrackerMonitorTrack/interface/MonitorTrackResiduals.cc
Monitoring source for track residuals on each detector module
*/
// Original Author:  Israel Goitom
//         Created:  Fri May 26 14:12:01 CEST 2006
// $Id: MonitorTrackResiduals.h,v 1.12 2008/03/01 11:24:56 dutta Exp $
#include <memory>
#include <fstream>
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DQMServices/Core/interface/MonitorElement.h"

typedef std::map<int, MonitorElement *> HistoClass;

class DQMStore;

class MonitorTrackResiduals : public edm::EDAnalyzer {
   public:
      explicit MonitorTrackResiduals(const edm::ParameterSet&);
      ~MonitorTrackResiduals();
      virtual void beginJob(edm::EventSetup const& iSetup);
      virtual void endJob(void);

      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      
      std::pair<std::string,int32_t> GetSubDetAndLayer(const uint32_t& detid);
      
 private:
      
      DQMStore * dqmStore_;
      edm::ParameterSet conf_;
      edm::ParameterSet Parameters;
      std::map< std::pair<std::string,int32_t>, MonitorElement* > m_SubdetLayerResiduals;
      std::map< std::pair<std::string,int32_t>, MonitorElement* > m_SubdetLayerNormedResiduals;
      HistoClass HitResidual;
      HistoClass NormedHitResiduals;
};
#endif
