#ifndef __Sphinx_TASK_H__
#define __Sphinx_TASK_H__

#include <coroutine>

namespace sphinx
{

namespace task
{

struct SphinxTaskPromise;

struct SphinxTask : std::coroutine_handle<SphinxTaskPromise>
{
    using promise_type = struct promise;
};

struct SphinxTaskPromise
{
    SphinxTask 
    get_return_object() { return {SphinxTask::from_promise(*this)};}

    std::suspend_always 
    initial_suspend() noexcept { return {}; }
    
    std::suspend_always 
    final_suspend() noexcept { return {}; }

    void return_void() {}
    void unhandled_exception() {}
};

}

}

#endif