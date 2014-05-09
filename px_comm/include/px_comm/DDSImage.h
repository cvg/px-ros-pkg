

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

namespace px_comm {

    extern const char *DDSImageTYPENAME;

    #ifdef __cplusplus
    struct DDSImageSeq;
    #ifndef NDDS_STANDALONE_TYPE
        class DDSImageTypeSupport;
    class DDSImageDataWriter;
    class DDSImageDataReader;
    #endif
    #endif

    class DDSImage 
    {
        public:
        #ifdef __cplusplus
            typedef struct DDSImageSeq Seq;
        #ifndef NDDS_STANDALONE_TYPE
            typedef DDSImageTypeSupport TypeSupport;
        typedef DDSImageDataWriter DataWriter;
        typedef DDSImageDataReader DataReader;
        #endif
            
        #endif

                                DDS_UnsignedLong   seq ;
        DDS_Long   stamp_sec ;
        DDS_Long   stamp_nsec ;
        DDS_Char *   frame_id ;
        DDS_UnsignedLong   height ;
        DDS_UnsignedLong   width ;
        DDS_Char *   encoding ;
        DDS_Char   is_bigendian ;
        DDS_UnsignedLong   step ;
        DDS_CharSeq  data ;
    };
    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
      /* If the code is building on Windows, start exporting symbols.
       */
    #undef NDDSUSERDllExport
      #define NDDSUSERDllExport __declspec(dllexport)
    #endif

    NDDSUSERDllExport DDS_TypeCode* DDSImage_get_typecode(void); /* Type code */

    DDS_SEQUENCE(DDSImageSeq, DDSImage);                                        

    NDDSUSERDllExport
    RTIBool DDSImage_initialize(
            DDSImage* self);

    NDDSUSERDllExport
    RTIBool DDSImage_initialize_ex(
            DDSImage* self,RTIBool allocatePointers,RTIBool allocateMemory);

    NDDSUSERDllExport
    RTIBool DDSImage_initialize_w_params(
            DDSImage* self,
            const struct DDS_TypeAllocationParams_t * allocParams);        

    NDDSUSERDllExport
    void DDSImage_finalize(
            DDSImage* self);

    NDDSUSERDllExport
    void DDSImage_finalize_ex(
            DDSImage* self,RTIBool deletePointers);

    NDDSUSERDllExport
    void DDSImage_finalize_w_params(
            DDSImage* self,
            const struct DDS_TypeDeallocationParams_t * deallocParams);

    NDDSUSERDllExport
    void DDSImage_finalize_optional_members(
            DDSImage* self, RTIBool deletePointers);  

    NDDSUSERDllExport
    RTIBool DDSImage_copy(
            DDSImage* dst,
            const DDSImage* src);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
      /* If the code is building on Windows, stop exporting symbols.
       */
    #undef NDDSUSERDllExport
      #define NDDSUSERDllExport
      #endif
} /* namespace px_comm  */

#endif /* DDSImage */

