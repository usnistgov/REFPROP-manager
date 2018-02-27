#include <string>
#include <map>
#include <memory>
#include <boost/preprocessor.hpp>
#include <boost/filesystem.hpp>

#define SEQ_LIST_OF_REFPROP_FUNCTION_NAMES() \
    (ABFL1dll) \
    (ABFL2dll) \
    (ABFLSHdll) \
    (ACTVYdll) \
    (AGdll) \
    (ALLPROP1dll) \
    (ALLPROPSdll) \
    (ALLPRP200dll) \
    (B12dll) \
    (BLCRVdll) \
    (CCRITdll) \
    (CHEMPOTdll) \
    (CP0dll) \
    (CRITPdll) \
    (CRTPNTdll) \
    (CSATKdll) \
    (CSTARdll) \
    (CV2PKdll) \
    (CVCPKdll) \
    (CVCPdll) \
    (DBDTdll) \
    (DBFL1dll) \
    (DBFL2dll) \
    (DDDPdll) \
    (DDDTdll) \
    (DEFL1dll) \
    (DEFLSHdll) \
    (DERVPVTdll) \
    (DHD1dll) \
    (DHFL1dll) \
    (DHFLSHdll) \
    (DIELECdll) \
    (DLSATKdll) \
    (DPDD2dll) \
    (DPDDdll) \
    (DPDTdll) \
    (DPTSATKdll) \
    (DQFL2dll) \
    (DSD1dll) \
    (DSFL1dll) \
    (DSFLSHdll) \
    (DVSATKdll) \
    (ENTHALdll) \
    (ENTROdll) \
    (ERRMSGdll) \
    (ESFLSHdll) \
    (EXCESSdll) \
    (FGCTY2dll) \
    (FGCTYdll) \
    (FLAGSdll) \
    (FPVdll) \
    (FUGCOFdll) \
    (GERG04dll) \
    (GERG08dll) \
    (GETENUMdll) \
    (GETFIJdll) \
    (GETKTVdll) \
    (GETMODdll) \
    (GIBBSdll) \
    (HEATFRMdll) \
    (HEATdll) \
    (HMXORDERdll) \
    (HSFL1dll) \
    (HSFLSHdll) \
    (IDCRVdll) \
    (INFOdll) \
    (JICRVdll) \
    (JTCRVdll) \
    (LIMITKdll) \
    (LIMITSdll) \
    (LIMITXdll) \
    (LIQSPNDLdll) \
    (MASSFLUXdll) \
    (MAXPdll) \
    (MAXTdll) \
    (MELTPdll) \
    (MELTTdll) \
    (MLTH2Odll) \
    (NAMEdll) \
    (PASSCMNdll) \
    (PDFL1dll) \
    (PDFLSHdll) \
    (PEFL1dll) \
    (PEFLSHdll) \
    (PHFL1dll) \
    (PHFLSHdll) \
    (PHI0dll) \
    (PHIDERVdll) \
    (PHIHMXdll) \
    (PHIKdll) \
    (PHIMIXdll) \
    (PHIXdll) \
    (PQFLSHdll) \
    (PREOSdll) \
    (PRESSdll) \
    (PSATKdll) \
    (PSFL1dll) \
    (PSFLSHdll) \
    (PUREFLDdll) \
    (QMASSdll) \
    (QMOLEdll) \
    (RDXHMXdll) \
    (REDXdll) \
    (REFPROP1dll) \
    (REFPROPdll) \
    (RESIDUALdll) \
    (RIEMdll) \
    (RMIX2dll) \
    (RPVersion) \
    (SATDdll) \
    (SATESTdll) \
    (SATEdll) \
    (SATGUESSdll) \
    (SATGVdll) \
    (SATHdll) \
    (SATPESTdll) \
    (SATPdll) \
    (SATSPLNdll) \
    (SATSdll) \
    (SATTESTdll) \
    (SATTPdll) \
    (SATTdll) \
    (SETAGAdll) \
    (SETFLUIDSdll) \
    (SETKTVdll) \
    (SETMIXTUREdll) \
    (SETMIXdll) \
    (SETMODdll) \
    (SETNCdll) \
    (SETPATHdll) \
    (SETREFdll) \
    (SETUPdll) \
    (SPLNROOTdll) \
    (SPLNVALdll) \
    (SUBLPdll) \
    (SUBLTdll) \
    (SURFTdll) \
    (SURTENdll) \
    (TDFLSHdll) \
    (TEFL1dll) \
    (TEFLSHdll) \
    (THERM0dll) \
    (THERM2dll) \
    (THERM3dll) \
    (THERMdll) \
    (THFL1dll) \
    (THFLSHdll) \
    (TPFL2dll) \
    (TPFLSHdll) \
    (TPRHOPRdll) \
    (TPRHOdll) \
    (TQFLSHdll) \
    (TRNPRPdll) \
    (TSATDdll) \
    (TSFL1dll) \
    (TSFLSHdll) \
    (UNSETAGAdll) \
    (VAPSPNDLdll) \
    (VIRBAdll) \
    (VIRBCDdll) \
    (VIRBdll) \
    (VIRCAdll) \
    (VIRCdll) \
    (WMOLIdll) \
    (WMOLdll) \
    (XMASSdll) \
    (XMOLEdll)

#define SEQ_ABFL1dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(char *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_ABFL2dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(INT_REF)(char *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_ABFLSHdll_ARGS() (char *)(DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_ACTVYdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(double *)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_AGdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_ALLPROP1dll_ARGS() (char *)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_ALLPROPSdll_ARGS() (char *)(INT_REF)(INT_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(char *)(int *)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_ALLPRP200dll_ARGS() (char *)(INT_REF)(INT_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(char *)(int *)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_B12dll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_BLCRVdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_CCRITdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_CHEMPOTdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_CP0dll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_CRITPdll_ARGS() (double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_CRTPNTdll_ARGS() (double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_CSATKdll_ARGS() (INT_REF)(DOUBLE_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_CSTARdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_CV2PKdll_ARGS() (INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_CVCPKdll_ARGS() (INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_CVCPdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_DBDTdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_DBFL1dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(char *)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_DBFL2dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(char *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_DDDPdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_DDDTdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_DEFL1dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_DEFLSHdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_DERVPVTdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_DHD1dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_DHFL1dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_DHFLSHdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_DIELECdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_DLSATKdll_ARGS() (INT_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_DPDD2dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_DPDDdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_DPDTdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_DPTSATKdll_ARGS() (INT_REF)(DOUBLE_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_DQFL2dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_DSD1dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_DSFL1dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_DSFLSHdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_DVSATKdll_ARGS() (INT_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_ENTHALdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_ENTROdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_ERRMSGdll_ARGS() (INT_REF)(char *)(RP_SIZE_T)
#define SEQ_ESFLSHdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_EXCESSdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_FGCTY2dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_FGCTYdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(double *)
#define SEQ_FLAGSdll_ARGS() (char *)(INT_REF)(INT_REF)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_FPVdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_FUGCOFdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_GERG04dll_ARGS() (INT_REF)(INT_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_GERG08dll_ARGS() (INT_REF)(INT_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_GETENUMdll_ARGS() (INT_REF)(char *)(INT_REF)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_GETFIJdll_ARGS() (char *)(double *)(char *)(char *)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_GETKTVdll_ARGS() (INT_REF)(INT_REF)(char *)(double *)(char *)(char *)(char *)(char *)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_GETMODdll_ARGS() (INT_REF)(char *)(char *)(char *)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_GIBBSdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_HEATFRMdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_HEATdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_HMXORDERdll_ARGS() (INT_REF)(INT_REF)(char *)(char *)(INT_REF)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_HSFL1dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_HSFLSHdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_IDCRVdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_INFOdll_ARGS() (INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_JICRVdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_JTCRVdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_LIMITKdll_ARGS() (char *)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_LIMITSdll_ARGS() (char *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(RP_SIZE_T)
#define SEQ_LIMITXdll_ARGS() (char *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_LIQSPNDLdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_MASSFLUXdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_MAXPdll_ARGS() (double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_MAXTdll_ARGS() (double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_MELTPdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_MELTTdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_MLTH2Odll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_NAMEdll_ARGS() (INT_REF)(char *)(char *)(char *)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_PASSCMNdll_ARGS() (char *)(INT_REF)(INT_REF)(INT_REF)(char *)(INT_REF)(DOUBLE_REF)(double *)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_PDFL1dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_PDFLSHdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_PEFL1dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_PEFLSHdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_PHFL1dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_PHFLSHdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_PHI0dll_ARGS() (INT_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_PHIDERVdll_ARGS() (INT_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(double *)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_PHIHMXdll_ARGS() (INT_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_PHIKdll_ARGS() (INT_REF)(INT_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_PHIMIXdll_ARGS() (INT_REF)(INT_REF)(INT_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_PHIXdll_ARGS() (INT_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_PQFLSHdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_PREOSdll_ARGS() (INT_REF)
#define SEQ_PRESSdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_PSATKdll_ARGS() (INT_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_PSFL1dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_PSFLSHdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_PUREFLDdll_ARGS() (INT_REF)
#define SEQ_QMASSdll_ARGS() (DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_QMOLEdll_ARGS() (DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_RDXHMXdll_ARGS() (INT_REF)(INT_REF)(INT_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_REDXdll_ARGS() (double *)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_REFPROP1dll_ARGS() (char *)(char *)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_REFPROPdll_ARGS() (char *)(char *)(char *)(INT_REF)(INT_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(char *)(INT_REF)(double *)(double *)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_RESIDUALdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_RIEMdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_RMIX2dll_ARGS() (double *)(DOUBLE_REF)
#define SEQ_RPVersion_ARGS() (char *)(RP_SIZE_T)
#define SEQ_SATDdll_ARGS() (DOUBLE_REF)(double *)(INT_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SATESTdll_ARGS() (INT_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(double *)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SATEdll_ARGS() (DOUBLE_REF)(double *)(INT_REF)(INT_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SATGUESSdll_ARGS() (INT_REF)(INT_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SATGVdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(INT_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SATHdll_ARGS() (DOUBLE_REF)(double *)(INT_REF)(INT_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SATPESTdll_ARGS() (DOUBLE_REF)(double *)(INT_REF)(DOUBLE_REF)(double *)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SATPdll_ARGS() (DOUBLE_REF)(double *)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SATSPLNdll_ARGS() (double *)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SATSdll_ARGS() (DOUBLE_REF)(double *)(INT_REF)(INT_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SATTESTdll_ARGS() (DOUBLE_REF)(double *)(INT_REF)(DOUBLE_REF)(double *)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SATTPdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SATTdll_ARGS() (DOUBLE_REF)(double *)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SETAGAdll_ARGS() (INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SETFLUIDSdll_ARGS() (char *)(INT_REF)(RP_SIZE_T)
#define SEQ_SETKTVdll_ARGS() (INT_REF)(INT_REF)(char *)(double *)(char *)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_SETMIXTUREdll_ARGS() (char *)(double *)(INT_REF)(RP_SIZE_T)
#define SEQ_SETMIXdll_ARGS() (char *)(char *)(char *)(INT_REF)(char *)(double *)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_SETMODdll_ARGS() (INT_REF)(char *)(char *)(char *)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_SETNCdll_ARGS() (INT_REF)
#define SEQ_SETPATHdll_ARGS() (char *)(RP_SIZE_T)
#define SEQ_SETREFdll_ARGS() (char *)(INT_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_SETUPdll_ARGS() (INT_REF)(char *)(char *)(char *)(INT_REF)(char *)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)(RP_SIZE_T)
#define SEQ_SPLNROOTdll_ARGS() (INT_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SPLNVALdll_ARGS() (INT_REF)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SUBLPdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SUBLTdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SURFTdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_SURTENdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_TDFLSHdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_TEFL1dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_TEFLSHdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_THERM0dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_THERM2dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_THERM3dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_THERMdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_THFL1dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_THFLSHdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_TPFL2dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_TPFLSHdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_TPRHOPRdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_TPRHOdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(INT_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_TQFLSHdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_TRNPRPdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_TSATDdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_TSFL1dll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_TSFLSHdll_ARGS() (DOUBLE_REF)(DOUBLE_REF)(double *)(INT_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(double *)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_UNSETAGAdll_ARGS() 
#define SEQ_VAPSPNDLdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)(INT_REF)(char *)(RP_SIZE_T)
#define SEQ_VIRBAdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_VIRBCDdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)(DOUBLE_REF)
#define SEQ_VIRBdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_VIRCAdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_VIRCdll_ARGS() (DOUBLE_REF)(double *)(DOUBLE_REF)
#define SEQ_WMOLIdll_ARGS() (INT_REF)(DOUBLE_REF)
#define SEQ_WMOLdll_ARGS() (double *)(DOUBLE_REF)
#define SEQ_XMASSdll_ARGS() (double *)(double *)(DOUBLE_REF)
#define SEQ_XMOLEdll_ARGS() (double *)(double *)(DOUBLE_REF)

#define REFPROP_ONLY_MACROS
#include "REFPROP_lib.h"
#undef REFPROP_ONLY_MACROS

#include "manyso/native.h"
#include "manyso/exceptions.h"

static std::string REFPROP_PATH = "";

#if defined(NOT_DLL)
#define EXPORT_CODE
#define CONVENTION 
#else
#include "EXPORTS.h"
#endif

class REFPROPInstance
{
private:
#define X(name) typedef void (RPCALLCONV name ## _TYPE)(name ## _ARGS);
    LIST_OF_REFPROP_FUNCTION_NAMES
#undef X
#define X(name) typedef name ## _TYPE * name ## _POINTER;
        LIST_OF_REFPROP_FUNCTION_NAMES
#undef X

        std::unique_ptr<NativeSharedLibraryWrapper> RP;
public:
    REFPROPInstance(const std::string &path, const std::string &shared_library_filename)
    {
        namespace fs = boost::filesystem;
        // See https://stackoverflow.com/a/8725664/1360263
        fs::path joined = (fs::path(path) / fs::path(shared_library_filename)).make_preferred();
        std::string shared_library_path = joined.string();
        if (!fs::is_regular_file(joined)) {
            throw std::invalid_argument("Constructed path to shared library is invalid:"+shared_library_path);
        }

        auto load_method = AbstractSharedLibraryWrapper::load_method::FROM_FILE;
        RP.reset(new NativeSharedLibraryWrapper(shared_library_path, load_method));

        // Check that the load was a success
        bool loaded_properly = std::get<0>(RP->is_locked());
        if (!loaded_properly) {
            throw InvalidLoad("Unable to load the shared library", 0);
        }

        // Set the path in REFPROP
        char * c_path = const_cast<char *>(path.c_str());
        SETPATHdll(c_path, path.size());
    }
    ~REFPROPInstance() {
        RP.release();
    }

    // And now, totally magical, the use of variadic function arguments in concert with type macros
    // Add many methods, each corresponding to a 1-to-1 wrapper of a function from the shared library
    #define X(name) template<class ...Args> void name(Args&&... args){ return RP->getAddress<name ## _POINTER>(#name)(std::forward<Args>(args)...); };
        LIST_OF_REFPROP_FUNCTION_NAMES
    #undef X
};

std::map<int, REFPROPInstance> handle_map;

/**
 @param path The path to the folder that contains the REFPROP shared library, as well as fluids and mixtures directories
 @param DLL_filename The filename (e.g., "REFPROP.dll") of the shared library that is to be loaded.  Make sure it matches the bitness of application
 @returns handle The handle to the returned DLL
 */
EXPORT_CODE int CONVENTION construct_handle(const char *path, const char *DLL_filename) {
    int next_handle = static_cast<int>(handle_map.size()) + 1;
    handle_map.emplace(std::piecewise_construct,
                       std::forward_as_tuple(next_handle),
                       std::forward_as_tuple(path, DLL_filename));
    return next_handle;
}

REFPROPInstance & get_instance(int handle) {
    auto it = handle_map.find(handle);
    if (it != handle_map.end()) {
        return it->second;
    }
    else {
        throw InvalidLoad("Could not get handle:" + std::to_string(handle) + " for pool of size ", 0);
    }
}

EXPORT_CODE int CONVENTION free_handle(int handle) {
    auto it = handle_map.find(handle);
    if (it != handle_map.end()) {
        handle_map.erase(it);
    }
    else {
        throw InvalidLoad("Could not free handle:" + std::to_string(handle) + " for pool of size ", 0);
    }
}

// generates for each Refprop-function
// extern "C" __declspec(dllexport) void __stdcall ABFL1dll(int handle, double &  arg_0, ... , std::size_t  arg_13) 
// { 
// 	get_instance(handle).ABFL1dll(arg_0, ..., arg_13); 
// };
// ...

#define RP_FUNCTION_PARAM_GENERATOR_MACRO(r, data, i, elem)          \
	BOOST_PP_COMMA() elem arg_##i 

#define RP_FUNCTION_ARG_GENERATOR_MACRO(r, data, i, elem)          \
	BOOST_PP_COMMA_IF(i) arg_##i 

#define RP_FUNCTION_GENERATOR_MACRO(r, data, elem)          \
	EXPORT_CODE void CONVENTION elem\
( int handle \
BOOST_PP_SEQ_FOR_EACH_I(RP_FUNCTION_PARAM_GENERATOR_MACRO,_,BOOST_PP_CAT(BOOST_PP_CAT(SEQ_,elem),_ARGS)()) \
)\
{ get_instance(handle).elem( \
BOOST_PP_SEQ_FOR_EACH_I(RP_FUNCTION_ARG_GENERATOR_MACRO,_,BOOST_PP_CAT(BOOST_PP_CAT(SEQ_,elem),_ARGS)()) \
); };

// export all functions
BOOST_PP_SEQ_FOR_EACH(RP_FUNCTION_GENERATOR_MACRO, _, SEQ_LIST_OF_REFPROP_FUNCTION_NAMES())

#if defined(REFMAN_TEST)
int main() {

    int handle = construct_handle("D:/Code/REFPROP-cmake/build/10/Release/","REFPRP64.dll");
    int nc = 1;
    int ierr = 0;
    char herr[255], hfld[] = "WATER.FLD", hhmx[] = "HMX.BNC", href[] = "DEF";
    SETUPdll(handle, nc, hfld, hhmx, href, ierr, herr, 10000, 255, 3, 255);

    int kq = 1;
    double z[] = { 1.0 }, x[] = { 1.0 }, y[] = { 1.0 }, T = 300, p = 101.325, d = -1, dl = -1, dv = -1, h = -1, s = -1, u = -1, cp = -1, cv = -1, q = 0, w = -1;
    PQFLSHdll(handle, p, q, z, kq, T, d, dl, dv, x, y, u, h, s, cp, cv, w, ierr, herr, 255);

    return EXIT_SUCCESS;
}
#endif