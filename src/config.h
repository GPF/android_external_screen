/* Copyright (c) 1991 Juergen Weigert (jnweiger@immd4.uni-erlangen.de)
 *                    Michael Schroeder (mlschroe@immd4.uni-erlangen.de)
 * Copyright (c) 1987 Oliver Laumann
 * All rights reserved.  Not derived from licensed software.
 *
 * Permission is granted to freely use, copy, modify, and redistribute
 * this software, provided that no attempt is made to gain profit from it,
 * the authors are not construed to be liable for any results of using the
 * software, alterations are clearly marked as such, and this notice is
 * not modified.
 *
 * Noteworthy contributors to screen's design and implementation:
 *	Wayne Davison (davison@borland.com)
 *	Patrick Wolfe (pat@kai.com, kailand!pat)
 *	Bart Schaefer (schaefer@cse.ogi.edu)
 *	Nathan Glasser (nathan@brokaw.lcs.mit.edu)
 *	Larry W. Virden (lwv27%cas.BITNET@CUNYVM.CUNY.Edu)
 *	Howard Chu (hyc@hanauma.jpl.nasa.gov)
 *	Tim MacKenzie (tym@dibbler.cs.monash.edu.au)
 *	Markku Jarvinen (mta@{cc,cs,ee}.tut.fi)
 *	Marc Boucher (marc@CAM.ORG)
 *
 ****************************************************************
 * $Id$ FAU
 */


/*
 *		Beginning of User Configuration Section
 *
 * First off, you should decide if you intend to install screen set-uid to
 * root.  This isn't necessary to use screen, but it allows the pseudo-ttys
 * to be set to their proper owner (for security purposes), /etc/utmp to be
 * updated, and /dev/kmem to be accessed to read the load average values.
 *
 * An alternative to installing screen set-uid root is to install it set-gid
 * utmp (with the file /etc/utmp installed to be group-utmp writable) or
 * set-gid kmem (with /dev/kmem set to be group-kmem readable) or some other
 * custom group to give you both.  The final alternative is to omit /etc/utmp
 * updating and the /dev/kmem reading (see the following defines) and simply
 * run screen as a regular program -- its major functions will be unaffected.
 */


/*
 * Define POSIX if your system supports IEEE Std 1003.1-1988 (POSIX).
 */
#undef POSIX

/*
 * Define BSDJOBS if you have BSD-style job control (both process
 * groups and a tty that deals correctly with them).
 */
#define BSDJOBS

/*
 * Define TERMIO if you have struct termio instead of struct sgttyb.
 * This is usually the case for SVID systems, where BSD uses sgttyb.
 * POSIX systems should define this anyway, even though they use
 * struct termios.
 */
#undef TERMIO

/*
 * Define TERMINFO if your machine emulates the termcap routines
 * with the terminfo database.
 * Thus the .screenrc file is parsed for
 * the command 'terminfo' and not 'termcap'.
 */
#undef TERMINFO

/*
 * Define SYSV if your machine is SYSV complient (Sys V, HPUX, A/UX)
 */
#undef SYSV

/*
 * Define SIGVOID if your signal handlers return void.  On older
 * systems, signal returns int, but on newer ones, it returns void.
 */
#undef SIGVOID 

/*
 * Define DIRENT if your system has <dirent.h> instead of <sys/dir.h>
 */
#undef DIRENT

/*
 * If screen is going to be installed set-uid root, you MUST define SUIDROOT.
 */
#define SUIDROOT

/*
 * If screen is installed with permissions to update /etc/utmp (such as if
 * it is installed set-uid root), define UTMPOK.  Set LOGINDEFAULT to one (1)
 * if you want entries added to /etc/utmp by default, else set it to zero (0).
 */
#define UTMPOK
#define LOGINDEFAULT	1

/*
 * If your system has getutent(), pututline(), etc. to write to the
 * utmp file, define GETUTENT.
 */
#undef GETUTENT

/*
 * Define UTHOST if the utmp file has a host field.
 */
#define UTHOST

/*
 * If UTMPOK is defined and your system (incorrectly) counts logins by
 * counting non-null entries in /etc/utmp (instead of counting non-null
 * entries with no hostname that are not on a pseudo tty), define USRLIMIT
 * to have screen put an upper-limit on the number of entries to write
 * into /etc/utmp.  This helps to keep you from exceeding a limited-user
 * license.
 */
#undef USRLIMIT

/*
 * If screen is NOT installed set-uid root, screen can provide tty security
 * by exclusively locking the ptys.  While this keeps other users from
 * opening your ptys, it also keeps your own subprocesses from being able
 * to open /dev/tty.  Define LOCKPTY to add this exclusive locking.
 */
#undef LOCKPTY

/*
 * If your system does not have the calls setreuid() and setregid(), define
 * NOREUID to force screen to use a forked process to safely create output
 * files without retaining any special privileges.  (Output logging will be
 * disabled, however.)
 */
#undef NOREUID

/*
 * If you want the "time" command to display the current load average
 * you must install screen with the needed privileges to read /dev/kmem
 * and have a load average format that screen understands.  We handle the
 * following formats:  3 doubles (BSD), 3 longs (sun), and 4 longs (alliant).
 */
#undef  LOADAV_3DOUBLES
#define LOADAV_3LONGS
#undef  LOADAV_4LONGS

/*
 * If your system has the new format /etc/ttys (like 4.3 BSD) and the
 * getttyent(3) library functions, define GETTTYENT.
 */
#undef GETTTYENT

/*
 * If your version of NFS supports named sockets and you install screen
 * suid root, you may need to define NFS_HACK for screen to be able to
 * open the sockets.
 */
#undef NFS_HACK

/*
 * By default screen will create a directory named ".screen" in the user's
 * HOME directory to contain the named sockets.  If this causes you problems
 * (e.g. some user's HOME directories are NFS-mounted and don't support
 * named sockets) you can have screen create the socket directories in a
 * common subdirectory, such as /tmp or /usr/tmp.  It makes things a little
 * more secure if you choose a directory where the "sticky" bit is on, but
 * this isn't required.  Screen will name the subdirectories "S-$USER"
 * (e.g /tmp/S-davison).
 * Do not define TMPTEST unless it's for debugging purpose.
 * If you want to have your socket directory in "/tmp/screens" then
 * define LOCALSOCKDIR and change the definition of SOCKDIR below.
 */
#define LOCALSOCKDIR

#ifdef LOCALSOCKDIR
# ifndef TMPTEST
#  define SOCKDIR "/local/screens"
# else
#  define SOCKDIR "/tmp/screens"
# endif
#endif

/*
 * Define USEBCOPY if the bcopy() from your system's C library supports the
 * overlapping of source and destination blocks.  When undefined, screen
 * uses its own (probably slower) version of bcopy().
 */
#undef USEBCOPY

/*
 * If you'd rather see the status line on the first line of your
 * terminal rather than the last, define TOPSTAT.
 */
#undef TOPSTAT

/*
 * If your system has vsprintf() and requires the use of the macros in
 * "varargs.h" to use functions with variable arguments,
 * define USEVARARGS.
 */
#undef USEVARARGS

/*
 * Define this if your system supports named pipes.
 */
#undef NAMEDPIPE

/*
 * here come the erlangen extensions to screen:
 * define LOCK if you want to use a lock program for a screenlock.
 * define PASSWORD for secure reattach of your screen.
 * define COPY_PASTE to use the famous hacker's treasure zoo.
 * define POW_DETACH to have a detach_and_logout key.
 * define REMOTE_DETACH (-d option) to move screen between terminals.
 * (jw)
 */
#define LOCK
#define PASSWORD
#define COPY_PASTE
#define REMOTE_DETACH
#define POW_DETACH

/*
 * As error messages are mostly meaningless to the user, we
 * try to throw out phrases that are somewhat more familiar
 * to ...well, at least familiar to us NetHack players.
 */
#define NETHACK

/*
 * and another sneaky feature: screen sources two startup files.
 * first a global file with a path specified here, second
 * your local $HOME/.screenrc
 * Don't define this, if you don't want it.
 */
#define ETCSCREENRC "/local/etc/screenrc"

/*
 *	End of User Configuration Section
 */
