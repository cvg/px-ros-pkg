
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDSImage.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#ifndef DDSImagePlugin_248003145_h
#define DDSImagePlugin_248003145_h

#include "DDSImage.h"




struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif


#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif


#ifdef __cplusplus
extern "C" {
#endif

#define px_comm_DDSImage_LAST_MEMBER_ID 0

#define px_comm_DDSImagePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define px_comm_DDSImagePlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define px_comm_DDSImagePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define px_comm_DDSImagePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define px_comm_DDSImagePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define px_comm_DDSImagePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern px_comm_DDSImage*
px_comm_DDSImagePluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern px_comm_DDSImage*
px_comm_DDSImagePluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
px_comm_DDSImagePluginSupport_copy_data(
    px_comm_DDSImage *out,
    const px_comm_DDSImage *in);

NDDSUSERDllExport extern void 
px_comm_DDSImagePluginSupport_destroy_data_ex(
    px_comm_DDSImage *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
px_comm_DDSImagePluginSupport_destroy_data(
    px_comm_DDSImage *sample);

NDDSUSERDllExport extern void 
px_comm_DDSImagePluginSupport_print_data(
    const px_comm_DDSImage *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
px_comm_DDSImagePlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
px_comm_DDSImagePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
px_comm_DDSImagePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
px_comm_DDSImagePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
px_comm_DDSImagePlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    px_comm_DDSImage *out,
    const px_comm_DDSImage *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
px_comm_DDSImagePlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const px_comm_DDSImage *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
px_comm_DDSImagePlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    px_comm_DDSImage *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
px_comm_DDSImagePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    px_comm_DDSImage **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
px_comm_DDSImagePlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
px_comm_DDSImagePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
px_comm_DDSImagePlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
px_comm_DDSImagePlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const px_comm_DDSImage * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
px_comm_DDSImagePlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
px_comm_DDSImagePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
px_comm_DDSImagePlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const px_comm_DDSImage *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
px_comm_DDSImagePlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    px_comm_DDSImage * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
px_comm_DDSImagePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    px_comm_DDSImage ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
px_comm_DDSImagePlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    px_comm_DDSImage *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
px_comm_DDSImagePlugin_new(void);

NDDSUSERDllExport extern void
px_comm_DDSImagePlugin_delete(struct PRESTypePlugin *);

#ifdef __cplusplus
}
#endif

        
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif        

#endif /* DDSImagePlugin_248003145_h */
