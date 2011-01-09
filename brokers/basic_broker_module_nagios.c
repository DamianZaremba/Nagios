/*
 * Basic nagios broker module
 *
 * Place in the module dir and compile with:
 * gcc -fPIC -o basic_template.o basic_template.c -shared
 *
 */
 
 /*
  * Are we building for nagios or icinga; 
  * They are mostly compatible but have some slightly different files
  */
 
#define ICINGA 1

/*
 * 
 * Include some required event broker stuff
 * 
 */
#include "../include/nebmodules.h"
#include "../include/nebcallbacks.h"
#include "../include/nebstructs.h"
#include "../include/broker.h"

/*
 * 
 * Include some required nagios/icinga
 * 
 */
#include "../include/config.h"
#include "../include/common.h"

#if ICINGA == 1
#include "../include/icinga.h"
#else
#include "../include/nagios.h"
#include "../include/objects.h"
#endif

/*
 * 
 * Include some core stuff
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 * Specify the event broker API version (we just use the current one)
 * 
 */
NEB_API_VERSION(CURRENT_NEB_API_VERSION);

/*
 * 
 * Debug enabled?
 * This would actually get set from a config file or option passed in a real broker
 * 
 */
int config_debug_enabled = 1;

/*
 *
 * Simple wrappers around the logging interface
 * 
 */ 
int log_registered_callback(char *callback, int result){
	/* These are debug messages, only carry out this if debug logging is enabled */
	if(config_debug_enabled == 0){
		return OK;
	}

	if(result == 0){
		/* Base message */
		char base_message[] = "base_template: [DEBUG] Registered %s successfully";
		
		/* Declate a var for the formatted message */
		char message[strlen(base_message) + strlen(callback) + sizeof(result)];
		
		/* Format the message */
		sprintf(message, base_message, callback);

		/* Actually write it */
		write_to_all_logs(message, NSLOG_INFO_MESSAGE);
	}else{
		/* Base message */
		char base_message[] = "base_template: [DEBUG] Failed to register %s (Result: %d)";
		
		/* Declate a var for the formatted message */
		char message[strlen(base_message) + strlen(callback) + sizeof(result)];
		
		/* Format the message */
		sprintf(message, base_message, callback, result);

		/* Actually write it */
		write_to_all_logs(message, NSLOG_INFO_MESSAGE);
	}
	return OK;
}

int log_unregistered_callback(char *callback, int result){
	/* These are debug messages, only carry out this if debug logging is enabled */
	if(config_debug_enabled == 0){
		return OK;
	}
	
	if(result == 0){
		/* Base message */
		char base_message[] = "base_template: [DEBUG] Un-registered %s successfully";
		
		/* Declate a var for the formatted message */
		char message[strlen(base_message) + strlen(callback) + sizeof(result)];
		
		/* Format the message */
		sprintf(message, base_message, callback);

		/* Actually write it */
		write_to_all_logs(message, NSLOG_INFO_MESSAGE);
	}else{
		/* Base message */
		char base_message[] = "base_template: [DEBUG] Failed to un-register %s (Result: %d)";
		
		/* Declate a var for the formatted message */
		char message[strlen(base_message) + strlen(callback) + sizeof(result)];
		
		/* Format the message */
		sprintf(message, base_message, callback, result);

		/* Actually write it */
		write_to_all_logs(message, NSLOG_INFO_MESSAGE);
	}
	return OK;
}

int module_error(char *error_message){
	char base_message[] = "base_template: [ERROR] %s";

	/* Declate a var for the formatted message */
	char message[strlen(base_message) + strlen(error_message)];
		
	/* Format the message */
	sprintf(message, base_message, error_message);

	/* Actually write it */
	write_to_all_logs(message, NSLOG_INFO_MESSAGE);
	return OK;
}

/*
 *
 * Function: base_template_handle_data
 * Called when a event we are registered for triggers
 * 
 */
int base_template_handle_data(int event_type, void *data){
	/* check we have data */
	if(data == NULL){
		return 0;
	}
	
	/* Make some vars for the below options */
	nebstruct_process_data *proc_data = NULL;
	nebstruct_timed_event_data *tevent_data = NULL;
	nebstruct_log_data *log_data = NULL;
	nebstruct_system_command_data *comamnd_data = NULL;
	nebstruct_event_handler_data *eventh_data = NULL;
	nebstruct_notification_data *notif_data = NULL;
	nebstruct_service_check_data *scheck_data = NULL;
	nebstruct_host_check_data *hcheck_data = NULL;
	nebstruct_comment_data *comment_data = NULL;
	nebstruct_downtime_data *downtime_data = NULL;
	nebstruct_flapping_data *flapping_data = NULL;
	nebstruct_program_status_data *pstatus_data = NULL;
	nebstruct_host_status_data *hstatus_data = NULL;
	nebstruct_service_status_data *sstatus_data = NULL;
	nebstruct_adaptive_program_data *adaptive_pdata = NULL;
	nebstruct_adaptive_host_data *adaptive_hdata = NULL;
	nebstruct_adaptive_service_data *adaptive_sdata = NULL;
	nebstruct_external_command_data *external_cdata = NULL;
	nebstruct_aggregated_status_data *aggregated_sdata = NULL;
	nebstruct_retention_data *retention_data = NULL;
	nebstruct_contact_notification_data *contact_notif_data = NULL;
	nebstruct_contact_notification_method_data *contact_notif_method_data = NULL;
	nebstruct_acknowledgement_data *ack_data = NULL;
	nebstruct_statechange_data *statechange_data = NULL;
	nebstruct_contact_status_data *contact_status_data = NULL;
	nebstruct_adaptive_contact_data *adaptive_cdata = NULL;

	/* work out what event we have */
	switch(event_type){
		case NEBCALLBACK_PROCESS_DATA:
			/* Information from the main nagios/icinga process */
			if((proc_data = (nebstruct_process_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_PROCESS_DATA");
				 */
			}
		break;

		case NEBCALLBACK_TIMED_EVENT_DATA:
			/* Timed event */
			if((tevent_data = (nebstruct_timed_event_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_TIMED_EVENT_DATA");
				 */
			}
		break;

		case NEBCALLBACK_SYSTEM_COMMAND_DATA:
			/* System commands */
			if((comamnd_data = (nebstruct_system_command_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_SYSTEM_COMMAND_DATA");
				 */
			}
		break;

		case NEBCALLBACK_EVENT_HANDLER_DATA:
			/* Event handlers */
			if((eventh_data = (nebstruct_event_handler_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_EVENT_HANDLER_DATA");
				 */
			}
		break;

		case NEBCALLBACK_NOTIFICATION_DATA:
			/* Notifications */
			if((notif_data = (nebstruct_notification_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_NOTIFICATION_DATA");
				 */
			}
		break;

		case NEBCALLBACK_SERVICE_CHECK_DATA:
			/* Service checks */
			if((scheck_data = (nebstruct_service_check_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_SERVICE_CHECK_DATA");
				 */
			}
		break;

		case NEBCALLBACK_HOST_CHECK_DATA:
			/* Host checks */
			if((hcheck_data = (nebstruct_host_check_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_HOST_CHECK_DATA");
				 */
			}
		break;

		case NEBCALLBACK_COMMENT_DATA:
			/* Comments */
			if((comment_data = (nebstruct_comment_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_COMMENT_DATA");
				 */
			}
		break;

		case NEBCALLBACK_DOWNTIME_DATA:
			/* Scheduled downtime */
			if((downtime_data = (nebstruct_downtime_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_DOWNTIME_DATA");
				 */
			}
		break;

		case NEBCALLBACK_FLAPPING_DATA:
			/* Flapping */
			if((flapping_data = (nebstruct_flapping_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_FLAPPING_DATA");
				 */
			}
		break;

		case NEBCALLBACK_PROGRAM_STATUS_DATA:
			/* Program status change */
			if((pstatus_data = (nebstruct_program_status_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_PROGRAM_STATUS_DATA");
				 */
			}
		break;

		case NEBCALLBACK_HOST_STATUS_DATA:
			/* Host status change */
			if((hstatus_data = (nebstruct_host_status_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_HOST_STATUS_DATA");
				 */
			}
		break;

		case NEBCALLBACK_SERVICE_STATUS_DATA:
			/* Service status change */
			if((sstatus_data = (nebstruct_service_status_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_SERVICE_STATUS_DATA");
				 */
			}
		break;

		case NEBCALLBACK_ADAPTIVE_PROGRAM_DATA:
			/* Adaptive program change */
			if((adaptive_pdata = (nebstruct_adaptive_program_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_ADAPTIVE_PROGRAM_DATA");
				 */
			}
		break;

		case NEBCALLBACK_ADAPTIVE_HOST_DATA:
			/* Adaptive host change */
			if((adaptive_hdata = (nebstruct_adaptive_host_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_ADAPTIVE_HOST_DATA");
				 */
			}
		break;

		case NEBCALLBACK_ADAPTIVE_SERVICE_DATA:
			/* Adaptive service change */
			if((adaptive_sdata = (nebstruct_adaptive_service_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_ADAPTIVE_SERVICE_DATA");
				 */
			}
		break;

		case NEBCALLBACK_EXTERNAL_COMMAND_DATA:
			/* External command processing */
			if((external_cdata = (nebstruct_external_command_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_EXTERNAL_COMMAND_DATA");
				 */
			}
		break;

		case NEBCALLBACK_AGGREGATED_STATUS_DATA:
			/* Aggregated status dump */
			if((aggregated_sdata = (nebstruct_aggregated_status_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_AGGREGATED_STATUS_DATA");
				 */
			}
		break;

		case NEBCALLBACK_RETENTION_DATA:
			/* Retention data loading/saving */
			if((retention_data = (nebstruct_retention_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_RETENTION_DATA");
				 */
			}
		break;

		case NEBCALLBACK_CONTACT_NOTIFICATION_DATA:
			/* Contact notification change */
			if((contact_notif_data = (nebstruct_contact_notification_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_CONTACT_NOTIFICATION_DATA");
				 */
			}
		break;

		case NEBCALLBACK_CONTACT_NOTIFICATION_METHOD_DATA:
			/* Contact notification method change */
			if((contact_notif_method_data = (nebstruct_contact_notification_method_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_CONTACT_NOTIFICATION_METHOD_DATA");
				 */
			}
		break;

		case NEBCALLBACK_ACKNOWLEDGEMENT_DATA:
			/* Acknowledgments */
			if((ack_data = (nebstruct_acknowledgement_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_ACKNOWLEDGEMENT_DATA");
				 */
			}
		break;

		case NEBCALLBACK_STATE_CHANGE_DATA:
			/* State changes */
			if((statechange_data = (nebstruct_statechange_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_STATE_CHANGE_DATA");
				 */
			}
		break;

		case NEBCALLBACK_CONTACT_STATUS_DATA:
			/* Contact status data */
			if((contact_status_data = (nebstruct_contact_status_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_CONTACT_STATUS_DATA");
				 */
			}
		break;

		case NEBCALLBACK_ADAPTIVE_CONTACT_DATA:
			/* Adaptive contact data */
			if((adaptive_cdata = (nebstruct_adaptive_contact_data *)data)){
				
			}else{
				/*
				 * This is spam fest central but useful for intense debugging
				 * log_debug("Ignoring triggered event NEBCALLBACK_ADAPTIVE_CONTACT_DATA");
				 */
			}
		break;

		default:
			/* We don't know about it so we don't care about it */
			return OK;
		break;
	}

	return OK;
}

/*
 *
 * Function: nebmodule_init
 * Called once when the module is loaded by the event broker
 * 
 */
int nebmodule_init(int flags, char *arg, nebmodule *handle){
	/* save our module handle */
	void *base_template_module_handle = handle;

	/* log the module load start */
	write_to_all_logs("base_template: Copyright: (c) 2011 Damian Zaremba. Version: 0.1", NSLOG_INFO_MESSAGE);
	write_to_all_logs("base_template: Initlizing callbacks", NSLOG_INFO_MESSAGE);
	
	/* register events to be notified of */
	int callback_priority = 0;
	int result = 0;

	if(result == 0)
		/* Information from the main nagios/icinga process */
		result = neb_register_callback(NEBCALLBACK_PROCESS_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_PROCESS_DATA", result);

	if(result == 0)
		/* Timed event */
		result = neb_register_callback(NEBCALLBACK_TIMED_EVENT_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_TIMED_EVENT_DATA", result);

	if(result == 0)
		/* Data being written to the log file */
		result = neb_register_callback(NEBCALLBACK_LOG_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_LOG_DATA", result);

	if(result == 0)
		/* System commands */
		result = neb_register_callback(NEBCALLBACK_SYSTEM_COMMAND_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_SYSTEM_COMMAND_DATA", result);

	if(result == 0)
		/* Event handlers */
		result = neb_register_callback(NEBCALLBACK_EVENT_HANDLER_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_EVENT_HANDLER_DATA", result);

	if(result == 0)
		/* Notifications */
		result = neb_register_callback(NEBCALLBACK_NOTIFICATION_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_NOTIFICATION_DATA", result);

	if(result == 0)
		/* Service checks */
		result = neb_register_callback(NEBCALLBACK_SERVICE_CHECK_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_SERVICE_CHECK_DATA", result);

	if(result == 0)
		/* Host checks */
		result = neb_register_callback(NEBCALLBACK_HOST_CHECK_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_HOST_CHECK_DATA", result);

	if(result == 0)
		/* Comments */
		result = neb_register_callback(NEBCALLBACK_COMMENT_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_COMMENT_DATA", result);

	if(result == 0)
		/* Scheduled downtime */
		result = neb_register_callback(NEBCALLBACK_DOWNTIME_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_DOWNTIME_DATA", result);

	if(result == 0)
		/* Flapping */
		result = neb_register_callback(NEBCALLBACK_FLAPPING_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_FLAPPING_DATA", result);

	if(result == 0)
		/* Program status change */
		result = neb_register_callback(NEBCALLBACK_PROGRAM_STATUS_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_PROGRAM_STATUS_DATA", result);

	if(result == 0)
		/* Host status change */
		result = neb_register_callback(NEBCALLBACK_HOST_STATUS_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_HOST_STATUS_DATA", result);

	if(result == 0)
		/* Service status change */
		result = neb_register_callback(NEBCALLBACK_SERVICE_STATUS_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_SERVICE_STATUS_DATA", result);

	if(result == 0)
		/* Adaptive program change */
		result = neb_register_callback(NEBCALLBACK_ADAPTIVE_PROGRAM_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_ADAPTIVE_PROGRAM_DATA", result);

	if(result == 0)
		/* Adaptive host change */
		result = neb_register_callback(NEBCALLBACK_ADAPTIVE_HOST_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_ADAPTIVE_HOST_DATA", result);

	if(result == 0)
		/* Adaptive service change */
		result = neb_register_callback(NEBCALLBACK_ADAPTIVE_SERVICE_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_ADAPTIVE_SERVICE_DATA", result);

	if(result == 0)
		/* External command processing */
		result = neb_register_callback(NEBCALLBACK_EXTERNAL_COMMAND_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_EXTERNAL_COMMAND_DATA", result);

	if(result == 0)
		/* Aggregated status dump */
		result = neb_register_callback(NEBCALLBACK_AGGREGATED_STATUS_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_AGGREGATED_STATUS_DATA", result);

	if(result == 0)
		/* Retention data loading/saving */
		result = neb_register_callback(NEBCALLBACK_RETENTION_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_RETENTION_DATA", result);

	if(result == 0)
		/* Contact notification change */
		result = neb_register_callback(NEBCALLBACK_CONTACT_NOTIFICATION_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_CONTACT_NOTIFICATION_DATA", result);

	if(result == 0)
		/* Contact notification method change */
		result = neb_register_callback(NEBCALLBACK_CONTACT_NOTIFICATION_METHOD_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_CONTACT_NOTIFICATION_METHOD_DATA", result);

	if(result == 0)
		/* Acknowledgments */
		result = neb_register_callback(NEBCALLBACK_ACKNOWLEDGEMENT_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_ACKNOWLEDGEMENT_DATA", result);

	if(result == 0)
		/* State changes */
		result = neb_register_callback(NEBCALLBACK_STATE_CHANGE_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_STATE_CHANGE_DATA", result);

	if(result == 0)
		/* Contact status data */
		result = neb_register_callback(NEBCALLBACK_CONTACT_STATUS_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_CONTACT_STATUS_DATA", result);

	if(result == 0)
		/* Adaptive contact data */
		result = neb_register_callback(NEBCALLBACK_ADAPTIVE_CONTACT_DATA, base_template_module_handle, callback_priority, base_template_handle_data);
		log_registered_callback("NEBCALLBACK_ADAPTIVE_CONTACT_DATA", result);

	if(result == 0)
		write_to_all_logs("base_template: Initialized successfully", NSLOG_INFO_MESSAGE);
	else
		write_to_all_logs("base_template: Initialization error", NSLOG_INFO_MESSAGE);

	return result;
}

/*
 *
 * Function: nebmodule_init
 * Called once when the module is un-loaded by the event broker
 * 
 */
int nebmodule_deinit(int flags, int reason){
	write_to_all_logs("base_template: Starting unload", NSLOG_INFO_MESSAGE);
	
	/* deregister events we registered for */
	int result = 0;

	/* Information from the main nagios/icinga process */
	result = neb_deregister_callback(NEBCALLBACK_PROCESS_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_PROCESS_DATA", result);

	/* Timed event */
	result = neb_deregister_callback(NEBCALLBACK_TIMED_EVENT_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_TIMED_EVENT_DATA", result);

	/* Data being written to the log file */
	result = neb_deregister_callback(NEBCALLBACK_LOG_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_LOG_DATA", result);

	/* System commands */
	result = neb_deregister_callback(NEBCALLBACK_SYSTEM_COMMAND_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_SYSTEM_COMMAND_DATA", result);

	/* Event handlers */
	result = neb_deregister_callback(NEBCALLBACK_EVENT_HANDLER_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_EVENT_HANDLER_DATA", result);

	/* Notifications */
	result = neb_deregister_callback(NEBCALLBACK_NOTIFICATION_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_NOTIFICATION_DATA", result);

	/* Service checks */
	result = neb_deregister_callback(NEBCALLBACK_SERVICE_CHECK_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_SERVICE_CHECK_DATA", result);

	/* Host checks */
	result = neb_deregister_callback(NEBCALLBACK_HOST_CHECK_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_HOST_CHECK_DATA", result);

	/* Comments */
	result = neb_deregister_callback(NEBCALLBACK_COMMENT_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_COMMENT_DATA", result);

	/* Scheduled downtime */
	result = neb_deregister_callback(NEBCALLBACK_DOWNTIME_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_DOWNTIME_DATA", result);

	/* Flapping */
	result = neb_deregister_callback(NEBCALLBACK_FLAPPING_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_FLAPPING_DATA", result);

	/* Program status change */
	result = neb_deregister_callback(NEBCALLBACK_PROGRAM_STATUS_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_PROGRAM_STATUS_DATA", result);

	/* Host status change */
	result = neb_deregister_callback(NEBCALLBACK_HOST_STATUS_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_HOST_STATUS_DATA", result);

	/* Service status change */
	result = neb_deregister_callback(NEBCALLBACK_SERVICE_STATUS_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_SERVICE_STATUS_DATA", result);

	/* Adaptive program change */
	result = neb_deregister_callback(NEBCALLBACK_ADAPTIVE_PROGRAM_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_ADAPTIVE_PROGRAM_DATA", result);

	/* Adaptive host change */
	result = neb_deregister_callback(NEBCALLBACK_ADAPTIVE_HOST_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_ADAPTIVE_HOST_DATA", result);

	/* Adaptive service change */
	result = neb_deregister_callback(NEBCALLBACK_ADAPTIVE_SERVICE_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_ADAPTIVE_SERVICE_DATA", result);

	/* External command processing */
	result = neb_deregister_callback(NEBCALLBACK_EXTERNAL_COMMAND_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_EXTERNAL_COMMAND_DATA", result);

	/* Aggregated status dump */
	result = neb_deregister_callback(NEBCALLBACK_AGGREGATED_STATUS_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_AGGREGATED_STATUS_DATA", result);

	/* Retention data loading/saving */
	result = neb_deregister_callback(NEBCALLBACK_RETENTION_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_RETENTION_DATA", result);

	/* Contact notification change */
	result = neb_deregister_callback(NEBCALLBACK_CONTACT_NOTIFICATION_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_CONTACT_NOTIFICATION_DATA", result);

	/* Contact notification method change */
	result = neb_deregister_callback(NEBCALLBACK_CONTACT_NOTIFICATION_METHOD_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_CONTACT_NOTIFICATION_METHOD_DATA", result);

	/* Acknowledgments */
	result = neb_deregister_callback(NEBCALLBACK_ACKNOWLEDGEMENT_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_ACKNOWLEDGEMENT_DATA", result);

	/* State changes */
	result = neb_deregister_callback(NEBCALLBACK_STATE_CHANGE_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_STATE_CHANGE_DATA", result);

	/* Contact status data */
	result = neb_deregister_callback(NEBCALLBACK_CONTACT_STATUS_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_CONTACT_STATUS_DATA", result);

	/* Adaptive contact data */
	result = neb_deregister_callback(NEBCALLBACK_ADAPTIVE_CONTACT_DATA, base_template_handle_data);
	log_unregistered_callback("NEBCALLBACK_ADAPTIVE_CONTACT_DATA", result);

	/* log the module unload */
	write_to_all_logs("base_template: Unloaded :'(", NSLOG_INFO_MESSAGE);

	return OK;
}
