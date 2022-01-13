include_directories( $ENV{PANDORA_INC} )
include_directories( $ENV{LARPANDORACONTENT_INC} )

set( 
          sliceid_tool_lib_list larcorealg_Geometry
                        larcore_Geometry_Geometry_service
                        larsim_Simulation lardataobj_Simulation
                        lardataobj_RawData
                        lardataobj_RecoBase
                        lardataobj_AnalysisBase
                        lardata_ArtDataHelper
                        lardata_Utilities
                        larreco_RecoAlg_ClusterRecoUtil
                        larreco_RecoAlg
                        larreco_ClusterFinder
                        larreco_Calorimetry
                        PandoraSDK
                        PandoraMonitoring
                        LArPandoraContent
                        larpandora_LArPandoraInterface
                        larpandora_LArPandoraEventBuilding
                        nusimdata::SimulationBase
                        art::Framework_Core
                        art::Framework_Principal
                        art::Framework_Services_Registry
                        art::Persistency_Common
                        art::Persistency_Provenance
                        art::Utilities
                        canvas::canvas
                        messagefacility::MF_MessageLogger
                        fhiclcpp::fhiclcpp
                        cetlib::cetlib cetlib_except
                        Boost::filesystem
                        ROOT::Geom
                        ROOT::GenVector
                        MODULE_LIBRARIES larpandora_LArPandoraEventBuilding
          )

art_make(TOOL_LIBRARIES ${sliceid_tool_lib_list})

install_headers()
install_fhicl()
install_source()
