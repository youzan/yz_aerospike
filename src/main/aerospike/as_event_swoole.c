#include <aerospike/as_event_swoole.h>
#include <aerospike/as_event_internal.h>


/******************************************************************************
 * GLOBALS
 *****************************************************************************/

as_event_swoole_callback* g_swoole_callback = 0;

/******************************************************************************
 * PUBLIC FUNCTIONS
 *****************************************************************************/

void as_event_set_swoole_callback(as_event_swoole_callback *swoole_callback) {
    g_swoole_callback = swoole_callback;
}

/******************************************************************************
 * SWOOLE FUNCTIONS
 *****************************************************************************/

#if defined(AS_USE_SWOOLE)

bool
as_event_create_loop(as_event_loop* event_loop)
{
    if (g_swoole_callback) {
        if (g_swoole_callback->create_loop_callback) {
            return g_swoole_callback->create_loop_callback(event_loop);
        }
    }
    return false;
}

void
as_event_register_external_loop(as_event_loop* event_loop)
{
    if (g_swoole_callback) {
        if (g_swoole_callback->register_external_loop_callback) {
            g_swoole_callback->register_external_loop_callback(event_loop);
        }
    }
}

bool
as_event_send(as_event_command* cmd)
{
    if (g_swoole_callback) {
        if (g_swoole_callback->send_callback) {
            return g_swoole_callback->send_callback(cmd);
        }
    }
    return false;
}

void
as_event_command_begin(as_event_command* cmd)
{
    if (g_swoole_callback) {
        if (g_swoole_callback->command_begin_callback) {
            g_swoole_callback->command_begin_callback(cmd);
        }
    }
}

void
as_event_close_connection(as_event_connection* conn)
{
    if (g_swoole_callback) {
        if (g_swoole_callback->close_connection_callback) {
            g_swoole_callback->close_connection_callback(conn);
        }
    }
}

void
as_event_node_destroy(as_node* node)
{
    if (g_swoole_callback) {
        if (g_swoole_callback->node_destroy_callback) {
            g_swoole_callback->node_destroy_callback(node);
        }
    }
}

bool
as_event_send_close_loop(as_event_loop* event_loop)
{
    if (g_swoole_callback) {
        if (g_swoole_callback->send_close_loop_callback) {
            return g_swoole_callback->send_close_loop_callback(event_loop);
        }
    }
    return false;
}

void
as_event_close_loop(as_event_loop* event_loop)
{
    if (g_swoole_callback) {
        if (g_swoole_callback->close_loop_callback) {
            g_swoole_callback->close_loop_callback(event_loop);
        }
    }
}


int
as_event_validate_connection(as_event_connection* conn)
{
    if (g_swoole_callback) {
        if (g_swoole_callback->validate_connection_callback) {
            return g_swoole_callback->validate_connection_callback(conn);
        }
    }
    return -1;
}

void
as_event_stop_timer(as_event_command* cmd)
{
    if (g_swoole_callback) {
        if (g_swoole_callback->stop_timer_callback) {
            g_swoole_callback->stop_timer_callback(cmd);
        }
    }
}

void
as_event_stop_watcher(as_event_command* cmd, as_event_connection* conn)
{
    if (g_swoole_callback) {
        if (g_swoole_callback->stop_watcher_callback) {
            g_swoole_callback->stop_watcher_callback(cmd, conn);
        }
    }
}

void
as_event_command_release(as_event_command* cmd)
{
    if (g_swoole_callback) {
        if (g_swoole_callback->command_release_callback) {
            g_swoole_callback->command_release_callback(cmd);
        }
    }
}

#endif