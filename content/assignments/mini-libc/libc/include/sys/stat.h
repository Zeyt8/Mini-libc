/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __SYS_STAT_H__
#define __SYS_STAT_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>

/*
 * These bits should be set in the mask argument of statx() to request
 * particular items when calling statx().
 */
#define STATX_TYPE		0x00000001U	/* Want/got stx_mode & S_IFMT */
#define STATX_MODE		0x00000002U	/* Want/got stx_mode & ~S_IFMT */
#define STATX_NLINK		0x00000004U	/* Want/got stx_nlink */
#define STATX_UID		0x00000008U	/* Want/got stx_uid */
#define STATX_GID		0x00000010U	/* Want/got stx_gid */
#define STATX_ATIME		0x00000020U	/* Want/got stx_atime */
#define STATX_MTIME		0x00000040U	/* Want/got stx_mtime */
#define STATX_CTIME		0x00000080U	/* Want/got stx_ctime */
#define STATX_INO		0x00000100U	/* Want/got stx_ino */
#define STATX_SIZE		0x00000200U	/* Want/got stx_size */
#define STATX_BLOCKS		0x00000400U	/* Want/got stx_blocks */
#define STATX_BASIC_STATS	0x000007ffU	/* The stuff in the normal stat struct */
#define STATX_BTIME		0x00000800U	/* Want/got stx_btime */
#define STATX_MNT_ID		0x00001000U	/* Got stx_mnt_id */

#define __S_IFMT		0170000	/* These bits determine file type.  */

/* File types.  */
#define __S_IFDIR		0040000	/* Directory.  */
#define __S_IFCHR		0020000	/* Character device.  */
#define __S_IFBLK		0060000	/* Block device.  */
#define __S_IFREG		0100000	/* Regular file.  */
#define __S_IFIFO		0010000	/* FIFO.  */
#define __S_IFLNK		0120000	/* Symbolic link.  */
#define __S_IFSOCK		0140000	/* Socket.  */

#define AT_EMPTY_PATH		0x1000

/* Structure describing file characteristics.  */
struct stat {
	mode_t st_mode;		/* File mode.  */
	ino_t st_ino;		/* File serial number.  */

	dev_t st_dev;		/* Device containing the file.  */
	nlink_t st_nlink;	/* Link count.  */

	uid_t st_uid;		/* User ID of the file's owner.  */
	gid_t st_gid;		/* Group ID of the file's group.  */

	off_t st_size;		/* Size of file, in bytes.  */

	uint32_t st_blksize;	/* Block size for filesystem I/O */
	uint64_t  st_blocks;	/* Number of 512B blocks allocated */

	int64_t st_atime;	/* Time of last access, in seconds, since 00:00:00 1st January 1970 UTC */
	int64_t st_mtime;	/* Time of last modification, in seconds, since 00:00:00 1st January 1970 UTC.  */
	int64_t st_ctime;	/* Time of last status change, in seconds, since 00:00:00 1st January 1970 UTC.  */
};

int stat(const char *__restrict, struct stat *__restrict);
int fstat(int fd, struct stat *st);
int fstatat(int fd, const char *restrict path, struct stat *restrict st, int flag);

#ifdef __cplusplus
}
#endif

#endif
