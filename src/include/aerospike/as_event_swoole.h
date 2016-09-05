//
//  as_event_swoole.h
//  aerospike_c_client
//
//  Created by 石伟 on 16/3/18.
//  Copyright (c) 2016年 石伟. All rights reserved.
//

#pragma once
#include <aerospike/as_event_internal.h>

#ifdef __cplusplus
extern "C" {
#endif
    typedef int (*as_event_validate_connection_callback)(as_event_connection* conn);
    
    typedef void (*as_event_stop_timer_callback)(as_event_command* cmd);
    
    typedef void (*as_event_stop_watcher_callback)(as_event_command* cmd, as_event_connection* conn);
    
    typedef void (*as_event_command_release_callback)(as_event_command* cmd);
    
    
    
    typedef bool (*as_event_create_loop_callback)(as_event_loop* event_loop);
    
    typedef void (*as_event_register_external_loop_callback)(as_event_loop* event_loop);
    
    typedef bool (*as_event_send_callback)(as_event_command* cmd);
    
    typedef void (*as_event_command_begin_callback)(as_event_command* cmd);
    
    typedef void (*as_event_close_connection_callback)(as_event_connection* conn);
    
    typedef void (*as_event_node_destroy_callback)(as_node* node);
    
    typedef bool (*as_event_send_close_loop_callback)(as_event_loop* event_loop);
    
    typedef void (*as_event_close_loop_callback)(as_event_loop* event_loop);
    
    typedef struct as_event_swoole_callback {
        as_event_validate_connection_callback validate_connection_callback;
        as_event_stop_timer_callback stop_timer_callback;
        as_event_stop_watcher_callback stop_watcher_callback;
        as_event_command_release_callback command_release_callback;
        as_event_create_loop_callback create_loop_callback;
        as_event_register_external_loop_callback register_external_loop_callback;
        as_event_send_callback  send_callback;
        as_event_command_begin_callback command_begin_callback;
        as_event_close_connection_callback close_connection_callback;
        as_event_node_destroy_callback node_destroy_callback;
        as_event_send_close_loop_callback   send_close_loop_callback;
        as_event_close_loop_callback    close_loop_callback;
    } as_event_swoole_callback;
    
    //as_event_swoole_callback* g_swoole_callback;
    
    void as_event_set_swoole_callback(as_event_swoole_callback* swoole_callback);

#ifdef __cplusplus
} // end extern "C"
#endif

