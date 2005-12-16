/* Copyright (c) 1991
 *      Juergen Weigert (jnweiger@immd4.informatik.uni-erlangen.de)
 *      Michael Schroeder (mlschroe@immd4.informatik.uni-erlangen.de)
 ****************************************************************
 * $Id$ FAU
 */
#define POSIX
#define BSDJOBS
#define TERMIO
#undef TERMINFO
#undef SYSV
#define SIGVOID 
#define DIRENT
#define SUIDROOT
#define UTMPOK
#define LOGINDEFAULT	1
#undef GETUTENT
#define UTHOST
#undef USRLIMIT
#undef LOCKPTY
#undef NOREUID
#undef  LOADAV_3DOUBLES
#define LOADAV_3LONGS
#undef  LOADAV_4LONGS
#undef GETTTYENT
#undef NFS_HACK
#define LOCALSOCKDIR

#ifdef LOCALSOCKDIR
# ifndef TMPTEST
#  define SOCKDIR "/tmp/screens"
# else
#  define SOCKDIR "/tmp/testscreens"
# endif
#endif
#undef USEBCOPY
#undef TOPSTAT
#undef USEVARARGS
#define NAMEDPIPE
#define LOCK
#define PASSWORD
#define COPY_PASTE
#define REMOTE_DETACH
#define POW_DETACH
#define NETHACK
#define ETCSCREENRC "/local/etc/screenrc"
