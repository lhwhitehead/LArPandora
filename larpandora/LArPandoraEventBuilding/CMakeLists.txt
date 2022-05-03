include_directories( $ENV{PANDORA_INC} ) ### MIGRATE-ACTION-RECOMMENDED (migrate-3.13.00) - avoid directory-scope functions: use target_link_libraries() with target semantics or target_include_directories() whenever possible
include_directories( $ENV{LARPANDORACONTENT_INC} ) ### MIGRATE-ACTION-RECOMMENDED (migrate-3.13.00) - avoid directory-scope functions: use target_link_libraries() with target semantics or target_include_directories() whenever possible
include_directories( $ENV{EIGEN_INC} ) ### MIGRATE-ACTION-RECOMMENDED (migrate-3.13.00) - avoid directory-scope functions: use target_link_libraries() with target semantics or target_include_directories() whenever possible

add_subdirectory(LArPandoraShower)
add_subdirectory(SliceIdTools)
add_subdirectory(fcl)

art_make( EXCLUDE SimpleNeutrinoId_tool.cc
          LIB_LIBRARIES larcorealg_Geometry
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
                        PANDORASDK
                        PANDORAMONITORING
                        LArPandoraContent
                        larpandora_LArPandoraInterface
                        larpandora_LArPandoraInterface_Detectors
                        nusimdata::SimulationBase
                        art::Framework_Core
                        art::Framework_Principal
                        art::Framework_Services_Registry
                        art_root_io::tfile_support
                        ROOT::Core
                        art_root_io::TFileService_service
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
          ) ### MIGRATE-ACTION-RECOMMENDED (migrate-3.13.00) - deprecated: use art_make_library(), art_dictonary(), and cet_build_plugin() with explicit source lists and plugin base types

install_headers()
install_fhicl()
install_source()
