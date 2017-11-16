#ifndef MipTrackFinder_h
#define MipTrackFinder_h 1

/*LCIO*/
#include "lcio.h"
#include "IMPL/LCCollectionVec.h"
#include "IMPL/ClusterImpl.h"
#include "EVENT/CalorimeterHit.h"
#include "EVENT/LCEvent.h"
#include "EVENT/LCIntVec.h"
#include "EVENT/Cluster.h"
#include "marlin/Processor.h"
#include "UTIL/LCTypedVector.h"

/*CALICE*/
#include "Mapper.hh"
#include "MappedContainer.hh"
#include "CellDescription.hh"

namespace CALICE {

  /** @brief Processor to extract MIP calibrations from muon beam runs
   * @author N.D'Ascenzo, DESY, S. Richter, DESY
   * @date Jul 13 2006, 2008
   */

  class MipTrackFinder : public marlin::Processor
  {

  public:
    /**Return new instance of this processor
     */
    virtual Processor* newProcessor() { return new MipTrackFinder;}
    /**Default constructor
     */
    MipTrackFinder();
    /**Destructor
     */
    ~MipTrackFinder();

    /**Initialise useful variables
     */
    virtual void init();
    /**Process event (the working horse)
       @param evt event to be processed
    */
    virtual void processEvent( LCEvent * evt );
    /**Function to be called at the end of the job, after all events have been processed, for clean up
     */
    virtual void end(){};

  private:
    /**Open the input collections
       @param evt event to be processed
    */
    void openInputCollections(LCEvent *evt);

    /**Find the track
       @param evt event to be processed
    */
    void findTrack(LCEvent *evt);

    /**Check if cuts are fullfilled, and if analysis is to be continued
       @return analyse flag to show if the cuts are fullfilled or not
    */
    bool doFurtherAnalysis();

    /**Extract AHCAL information
     */
    LCTypedVector<CalorimeterHit> extractAHCALInformation();

    /**Extract number of hits and the energy sum from the input collection
       @param inputCol the input collection
    */
    std::pair<int, float> extractNumberOfHitsAndEnergySum(LCCollection *inputCol);

    /**Find clusters of MIP tracks
       @param hcalVec input vector of AHCAL hits
       @return vector of clusters
    */
    EVENT::ClusterVec findTrackClusters(LCTypedVector<CalorimeterHit> hcalVec);

    /**Select good tracks
       @param clusterVec vector of track clusters, on which the selection is performed
       @param trackSelectionMode track selection mode, set by the steering parameter TrackSelectionMode
    */
    EVENT::ClusterVec selectTrackClusters(EVENT::ClusterVec clusterVec,
                                          const std::string trackSelectionMode);

    /**Get the whole track (i.e. track with no missing hits)
       @param trackCluster input track cluster, from which the mean X and Y of the track are calculated
       @return wholeTrack the track cluster which contains all the hits
    */
    ClusterImpl* getWholeTrack(Cluster *trackCluster);

    /**Get the vector of track clusters containing all the remaining hits
       @param selectedTrackClusters vector of selected track clusters
       @return vector of track clusters containing all the remaining hits
    */
    EVENT::ClusterVec getRemainingHits(EVENT::ClusterVec selectedTrackClusters);

    /**Append event parameters with basic track information
       @param evt the processed event
       @param finalVec final vector of track clusters, after all selections
    */
    void appendParameters(LCEvent *evt, EVENT::ClusterVec finalVec);

    /**Create output collection of track clusters
       @param evt the processed event
       @param finalVec final vector of track clusters, after all selections
    */
    void createOutputCollection(LCEvent *evt, EVENT::ClusterVec finalVec);

  private:
    const Mapper* _mapper; /**<the mapper*/
    std::string _mappingProcessorName;        /**<name of the processor which provides the mapping*/
    std::string _cellDescriptionProcessorName;/**<name of the processor which provides the cells description*/
    MappedContainer<CALICE::CellDescription> *_cellDescriptions;    /**<mapped container of cells description*/

    LCCollection *_ecalInputCol;/**<ECAL input collection*/
    LCCollection *_ahcalInputCol;/**<AHCAL input collection*/
    LCCollection *_ahcalAmpInputCol;/**<AHCAL Amplitude input collection*/
    LCCollection *_tcmtInputCol;/**<TCMT input collection*/

    std::string _ecalInputColName;
    std::string _ahcalInputColName;
    std::string _ahcalAmpInputColName;
    std::string _ahcalOutputTrackColName;
    std::string _tcmtInputColName;
    std::string _trackSelectionMode; /**<track selection mode: NHITs = based on the number of hits;
                                        PERPENDICULAR = select only perpendicular tracks*/

    bool _useECALandTCMT;     /**<decide whether to use ECAL and TCMT input information (default: false)*/
    bool _isNonMuonRun;       /**<flag for non-muon run*/
    int _ahcalMaxNoHits;      /**<maximum number of hits in the AHCAL*/
    int _ecalMinNoHits;       /**<minimum number of hits in the ECAL*/
    int _ecalMaxNoHits;       /**<maximum number of hits in the ECAL*/
    float _tcmtMinEnergySum;  /**<minimum energy sum in the TCMT*/
    float _mipCutValue;       /**<MIP cut value (0.5 MIPs)*/
    int _mipCutVariable;      /** choose amplitude to be used to perform the mip cut */
    int _trackNoHitsThreshold; /**<minimum number of hits for which a track is considered to be
                                  a muon track (used only with TrackSelectionMode=NHITS)*/

    IntVec _badAhcalModulesVec;  /**<vector of bad AHCAL modules numbers*/
    IntVec _firstAhcalModulesVec;/**<vector of numbers of the beginning AHCAL modules which are
                                    used for perpendicular track finding*/
    IntVec _lastAhcalModulesVec; /**<vector of numbers of the ending AHCAL modules which are
                                    used for perpendicular track finding*/
    EVENT::CalorimeterHitVec _allAhcalHitsInEventVec; /**<vector containing all AHCAL hits from the event*/

  };/*end of class*/
}/*end of namespace CALICE*/

#endif
