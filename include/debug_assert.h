#ifndef DEBUG_ASSERT_H__
#define DEBUG_ASSERT_H__

#ifdef DEBUG

#define D_ASSERT(state) assert(state)

#else

#define D_ASSERT(state)

#endif

#endif // DEBUG_ASSERT_H__
