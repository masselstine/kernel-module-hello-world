// SPDX-License-Identifier: GPL-2.0 OR MIT
/*
 * hello-world - a module that prints some strings
 *               to dmesg at load/unload.
 *
 * Copyright (C) 2019 Mark Asselstine
 *
 *
 */
#include <linux/init.h>
#include <linux/module.h>


/* See module.h for additional #defines you may want to customize*/
MODULE_LICENSE("Dual MIT/GPL"); /* See module.h for acceptable options */
MODULE_AUTHOR("Homer Simpson");
MODULE_DESCRIPTION("A hello-world kernel module");
MODULE_VERSION("0.1");

/* Initialize the module, called when first loaded */
static int __init hello_world_init(void) {
  /* print "Hello World" to the dmesg on module load */
  printk(KERN_INFO "Hello World\n");
}

/* Last call before module unload, complete any cleanup */
static void __exit hello_world_exit(void) {
  /* print "Goodby World" to the dmesg on module unload */
  printk(KERN_INFO "Goodbye World\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);
