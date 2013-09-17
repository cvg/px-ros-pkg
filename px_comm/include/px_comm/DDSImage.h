
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDSImage.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#ifndef DDSImage_248003145_h
#define DDSImage_248003145_h

#ifndef NDDS_STANDALONE_TYPE
    #ifdef __cplusplus
        #ifndef ndds_cpp_h
            #include "ndds/ndds_cpp.h"
        #endif
    #else
        #ifndef ndds_c_h
            #include "ndds/ndds_c.h"
        #endif
    #endif
#else
    #include "ndds_standalone_type.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *px_comm_DDSImageTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct px_comm_DDSImageSeq;

#ifndef NDDS_STANDALONE_TYPE
    class px_comm_DDSImageTypeSupport;
    class px_comm_DDSImageDataWriter;
    class px_comm_DDSImageDataReader;
#endif

#endif

            
    
class px_comm_DDSImage                                        
{
public:            
#ifdef __cplusplus
    typedef struct px_comm_DDSImageSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef px_comm_DDSImageTypeSupport TypeSupport;
    typedef px_comm_DDSImageDataWriter DataWriter;
    typedef px_comm_DDSImageDataReader DataReader;
#endif

#endif
    
    DDS_UnsignedLong  seq;

    DDS_Long  stamp_sec;

    DDS_Long  stamp_nsec;

    char*  frame_id; /* maximum length = (255) */

    DDS_UnsignedLong  height;

    DDS_UnsignedLong  width;

    char*  encoding; /* maximum length = (255) */

    DDS_Char  is_bigendian;

    DDS_UnsignedLong  step;

     DDS_CharSeq  data;

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* px_comm_DDSImage_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(px_comm_DDSImageSeq, px_comm_DDSImage);
        
NDDSUSERDllExport
RTIBool px_comm_DDSImage_initialize(
        px_comm_DDSImage* self);
        
NDDSUSERDllExport
RTIBool px_comm_DDSImage_initialize_ex(
        px_comm_DDSImage* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
void px_comm_DDSImage_finalize(
        px_comm_DDSImage* self);
                        
NDDSUSERDllExport
void px_comm_DDSImage_finalize_ex(
        px_comm_DDSImage* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool px_comm_DDSImage_copy(
        px_comm_DDSImage* dst,
        const px_comm_DDSImage* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* DDSImage_248003145_h */
