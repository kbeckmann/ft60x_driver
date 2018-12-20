#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x4db908d1, "module_layout" },
	{ 0x9883c4d2, "noop_llseek" },
	{ 0xd4110083, "usb_deregister" },
	{ 0x343c8487, "usb_register_driver" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x1000e51, "schedule" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x3cee3b01, "mutex_lock_interruptible" },
	{ 0xcd47c6a1, "usb_register_dev" },
	{ 0xd2b09ce5, "__kmalloc" },
	{ 0x58d32e7f, "usb_get_dev" },
	{ 0x9a76f11f, "__mutex_init" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xaada084a, "usb_unlink_urb" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x301fa007, "_raw_spin_unlock" },
	{ 0xdbf17652, "_raw_spin_lock" },
	{ 0xa347404d, "usb_unanchor_urb" },
	{ 0x9be2f1c2, "_dev_err" },
	{ 0xcf2a6966, "up" },
	{ 0x81b395b3, "down_interruptible" },
	{ 0x3c1adb8a, "usb_submit_urb" },
	{ 0x3ae5ba15, "usb_anchor_urb" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x68d66a95, "usb_alloc_coherent" },
	{ 0xc9992ecb, "usb_alloc_urb" },
	{ 0xfc7e2596, "down_trylock" },
	{ 0xb44ad4b3, "_copy_to_user" },
	{ 0x813128bd, "usb_control_msg" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x362ef408, "_copy_from_user" },
	{ 0xbea36ebe, "usb_autopm_get_interface" },
	{ 0xc2a99e1f, "usb_find_interface" },
	{ 0x27c6bdd2, "usb_autopm_put_interface" },
	{ 0x7c32d0f0, "printk" },
	{ 0xdb7305a1, "__stack_chk_fail" },
	{ 0x35ca9e6c, "usb_bulk_msg" },
	{ 0x70382261, "kmem_cache_alloc_trace" },
	{ 0x404b4d94, "kmalloc_caches" },
	{ 0x104f05ca, "_dev_info" },
	{ 0xb348a850, "ex_handler_refcount" },
	{ 0xb0fda379, "usb_deregister_dev" },
	{ 0x37a0cba, "kfree" },
	{ 0x69b0224, "usb_free_coherent" },
	{ 0xde61522f, "usb_put_dev" },
	{ 0x8b593e18, "usb_free_urb" },
	{ 0xc5664491, "_raw_spin_unlock_irq" },
	{ 0x47941711, "_raw_spin_lock_irq" },
	{ 0x41aed6e7, "mutex_lock" },
	{ 0x962c8ae1, "usb_kill_anchored_urbs" },
	{ 0x20eb7e9a, "usb_kill_urb" },
	{ 0x407af304, "usb_wait_anchor_empty_timeout" },
	{ 0xa6093a32, "mutex_unlock" },
	{ 0x2ea2c95c, "__x86_indirect_thunk_rax" },
	{ 0xbdfb6dbb, "__fentry__" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v0403p601Ed*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "806AC2D574DFF74B1E5AC2B");
