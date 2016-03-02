#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x2ab9dba5, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xa457d9ca, __VMLINUX_SYMBOL_STR(register_netdevice) },
	{ 0x423771e2, __VMLINUX_SYMBOL_STR(dev_mc_sync_multiple) },
	{ 0xd4e82f04, __VMLINUX_SYMBOL_STR(skb_flow_get_ports) },
	{ 0x8733c9e1, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xf6738769, __VMLINUX_SYMBOL_STR(rtmsg_ifinfo) },
	{ 0x4c4fef19, __VMLINUX_SYMBOL_STR(kernel_stack) },
	{ 0x779af202, __VMLINUX_SYMBOL_STR(dev_mc_unsync) },
	{ 0x349cba85, __VMLINUX_SYMBOL_STR(strchr) },
	{ 0xb6b46a7c, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0x43a53735, __VMLINUX_SYMBOL_STR(__alloc_workqueue_key) },
	{ 0x461d88bc, __VMLINUX_SYMBOL_STR(skb_flow_dissect) },
	{ 0x12b9bc9a, __VMLINUX_SYMBOL_STR(seq_open) },
	{ 0xce73ebce, __VMLINUX_SYMBOL_STR(vlan_dev_vlan_id) },
	{ 0x79aa04a2, __VMLINUX_SYMBOL_STR(get_random_bytes) },
	{ 0x3fb8a666, __VMLINUX_SYMBOL_STR(seq_puts) },
	{ 0xbea2079d, __VMLINUX_SYMBOL_STR(netdev_rx_handler_register) },
	{ 0xc7a4fbed, __VMLINUX_SYMBOL_STR(rtnl_lock) },
	{ 0x821a511, __VMLINUX_SYMBOL_STR(vlan_uses_dev) },
	{ 0x8b900f3b, __VMLINUX_SYMBOL_STR(_raw_read_lock) },
	{ 0x1a5f6a16, __VMLINUX_SYMBOL_STR(netif_carrier_on) },
	{ 0xca5e095b, __VMLINUX_SYMBOL_STR(dst_release) },
	{ 0x1637ff0f, __VMLINUX_SYMBOL_STR(_raw_spin_lock_bh) },
	{ 0xc87bba4d, __VMLINUX_SYMBOL_STR(skb_clone) },
	{ 0x6b06fdce, __VMLINUX_SYMBOL_STR(delayed_work_timer_fn) },
	{ 0x91831d70, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0xd2da1048, __VMLINUX_SYMBOL_STR(register_netdevice_notifier) },
	{ 0x5fbe341e, __VMLINUX_SYMBOL_STR(netif_carrier_off) },
	{ 0xeec850c6, __VMLINUX_SYMBOL_STR(netdev_master_upper_dev_get) },
	{ 0xd791cc7, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0xf087137d, __VMLINUX_SYMBOL_STR(__dynamic_pr_debug) },
	{ 0x70b37b91, __VMLINUX_SYMBOL_STR(dev_set_allmulti) },
	{ 0xede1872f, __VMLINUX_SYMBOL_STR(vlan_vid_del) },
	{ 0x6361d69f, __VMLINUX_SYMBOL_STR(call_netdevice_notifiers) },
	{ 0xee0f75e4, __VMLINUX_SYMBOL_STR(__dev_kfree_skb_any) },
	{ 0x593a99b, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0x797c8fa9, __VMLINUX_SYMBOL_STR(cancel_delayed_work_sync) },
	{ 0x703dfdb2, __VMLINUX_SYMBOL_STR(kobject_del) },
	{ 0x36362c31, __VMLINUX_SYMBOL_STR(vlan_vid_add) },
	{ 0x4d1bc3fa, __VMLINUX_SYMBOL_STR(__netpoll_setup) },
	{ 0x16e6237b, __VMLINUX_SYMBOL_STR(vlan_vids_del_by_dev) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0xa692f01a, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0x9d0d6206, __VMLINUX_SYMBOL_STR(unregister_netdevice_notifier) },
	{ 0x1513a463, __VMLINUX_SYMBOL_STR(skb_trim) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0x190e4dae, __VMLINUX_SYMBOL_STR(vlan_vids_add_by_dev) },
	{ 0x1ef7ebce, __VMLINUX_SYMBOL_STR(dev_mc_add) },
	{ 0x190b5c8d, __VMLINUX_SYMBOL_STR(__netdev_alloc_skb) },
	{ 0xeb71b818, __VMLINUX_SYMBOL_STR(netdev_lower_get_next_private_rcu) },
	{ 0xbe561acf, __VMLINUX_SYMBOL_STR(__pskb_pull_tail) },
	{ 0x6be500a1, __VMLINUX_SYMBOL_STR(netdev_change_features) },
	{ 0x5a245503, __VMLINUX_SYMBOL_STR(netpoll_send_skb_on_dev) },
	{ 0xc671e369, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0xa3a1283, __VMLINUX_SYMBOL_STR(PDE_DATA) },
	{ 0xf216c016, __VMLINUX_SYMBOL_STR(netdev_has_upper_dev) },
	{ 0x5d41c87c, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0x904649d, __VMLINUX_SYMBOL_STR(dev_set_mac_address) },
	{ 0x8b34e227, __VMLINUX_SYMBOL_STR(unregister_pernet_subsys) },
	{ 0xf2af955a, __VMLINUX_SYMBOL_STR(proc_mkdir) },
	{ 0x9fdecc31, __VMLINUX_SYMBOL_STR(unregister_netdevice_many) },
	{ 0x11089ac7, __VMLINUX_SYMBOL_STR(_ctype) },
	{ 0x8e663bd9, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0xf8ef3aca, __VMLINUX_SYMBOL_STR(arp_create) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x161571df, __VMLINUX_SYMBOL_STR(ethtool_op_get_link) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0x9e763530, __VMLINUX_SYMBOL_STR(reciprocal_value) },
	{ 0xd2936c14, __VMLINUX_SYMBOL_STR(ns_capable) },
	{ 0x2dc10d7f, __VMLINUX_SYMBOL_STR(kobject_init_and_add) },
	{ 0xb3844789, __VMLINUX_SYMBOL_STR(__netpoll_free_async) },
	{ 0x62849ac7, __VMLINUX_SYMBOL_STR(dev_valid_name) },
	{ 0xcafd1c2c, __VMLINUX_SYMBOL_STR(netdev_class_remove_file_ns) },
	{ 0xbf94fcf8, __VMLINUX_SYMBOL_STR(__ethtool_get_settings) },
	{ 0xa6624490, __VMLINUX_SYMBOL_STR(free_netdev) },
	{ 0x9166fada, __VMLINUX_SYMBOL_STR(strncpy) },
	{ 0x46b3acbc, __VMLINUX_SYMBOL_STR(dev_mc_del) },
	{ 0xb9767e74, __VMLINUX_SYMBOL_STR(nla_put) },
	{ 0x8bc549b4, __VMLINUX_SYMBOL_STR(netdev_upper_dev_unlink) },
	{ 0x5a921311, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0x5792f848, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x4b26f12d, __VMLINUX_SYMBOL_STR(skb_push) },
	{ 0x8c03d20c, __VMLINUX_SYMBOL_STR(destroy_workqueue) },
	{ 0x645c51f1, __VMLINUX_SYMBOL_STR(dev_close) },
	{ 0xf4f14de6, __VMLINUX_SYMBOL_STR(rtnl_trylock) },
	{ 0xc2cdbf1, __VMLINUX_SYMBOL_STR(synchronize_sched) },
	{ 0x2e9ac971, __VMLINUX_SYMBOL_STR(dev_mc_flush) },
	{ 0xa735db59, __VMLINUX_SYMBOL_STR(prandom_u32) },
	{ 0xdc329cd4, __VMLINUX_SYMBOL_STR(inet_confirm_addr) },
	{ 0x7ceeca24, __VMLINUX_SYMBOL_STR(init_net) },
	{ 0x5babfabc, __VMLINUX_SYMBOL_STR(rtnl_link_unregister) },
	{ 0xb56f7dc4, __VMLINUX_SYMBOL_STR(__dev_get_by_index) },
	{ 0x4eee5892, __VMLINUX_SYMBOL_STR(netdev_lower_dev_get_private) },
	{ 0x3c2dc5ca, __VMLINUX_SYMBOL_STR(dev_open) },
	{ 0x9dec2af2, __VMLINUX_SYMBOL_STR(netdev_master_upper_dev_link_private) },
	{ 0x5148e53a, __VMLINUX_SYMBOL_STR(dev_uc_flush) },
	{ 0x78764f4e, __VMLINUX_SYMBOL_STR(pv_irq_ops) },
	{ 0x41b87b6d, __VMLINUX_SYMBOL_STR(netdev_upper_get_next_dev_rcu) },
	{ 0x69b13283, __VMLINUX_SYMBOL_STR(sysfs_remove_file_ns) },
	{ 0xba63339c, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_bh) },
	{ 0xeeec26a7, __VMLINUX_SYMBOL_STR(queue_delayed_work_on) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x6de62ad6, __VMLINUX_SYMBOL_STR(vlan_dev_vlan_proto) },
	{ 0xc20f6b5c, __VMLINUX_SYMBOL_STR(netdev_rx_handler_unregister) },
	{ 0x3bd1b1f6, __VMLINUX_SYMBOL_STR(msecs_to_jiffies) },
	{ 0x79a38e61, __VMLINUX_SYMBOL_STR(___ratelimit) },
	{ 0x17673717, __VMLINUX_SYMBOL_STR(kfree_skb) },
	{ 0xaccabc6a, __VMLINUX_SYMBOL_STR(in4_pton) },
	{ 0x6b2dc060, __VMLINUX_SYMBOL_STR(dump_stack) },
	{ 0xbff1063f, __VMLINUX_SYMBOL_STR(alloc_netdev_mqs) },
	{ 0x3067c66d, __VMLINUX_SYMBOL_STR(arp_xmit) },
	{ 0x70ebb85, __VMLINUX_SYMBOL_STR(netdev_lower_get_next_private) },
	{ 0x414dba15, __VMLINUX_SYMBOL_STR(register_pernet_subsys) },
	{ 0x32a009e5, __VMLINUX_SYMBOL_STR(pskb_expand_head) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x3fc95f0a, __VMLINUX_SYMBOL_STR(ether_setup) },
	{ 0xb35e5e30, __VMLINUX_SYMBOL_STR(dev_uc_unsync) },
	{ 0x3f453d3f, __VMLINUX_SYMBOL_STR(__dev_get_by_name) },
	{ 0x20705009, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xd52bf1ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xcd48ca18, __VMLINUX_SYMBOL_STR(unregister_netdevice_queue) },
	{ 0xa0f38ebf, __VMLINUX_SYMBOL_STR(ip_route_output_flow) },
	{ 0xf6ebc03b, __VMLINUX_SYMBOL_STR(net_ratelimit) },
	{ 0x701b1101, __VMLINUX_SYMBOL_STR(_raw_write_unlock_bh) },
	{ 0x308992c, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0x349456e4, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0x50277348, __VMLINUX_SYMBOL_STR(_raw_read_lock_bh) },
	{ 0xcf2cea31, __VMLINUX_SYMBOL_STR(_raw_read_unlock_bh) },
	{ 0xee9e1b79, __VMLINUX_SYMBOL_STR(dev_set_promiscuity) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xf6af2346, __VMLINUX_SYMBOL_STR(dev_uc_sync_multiple) },
	{ 0x20b2bb2d, __VMLINUX_SYMBOL_STR(param_array_ops) },
	{ 0xd225ddb1, __VMLINUX_SYMBOL_STR(dev_trans_start) },
	{ 0xa4453079, __VMLINUX_SYMBOL_STR(rtnl_link_register) },
	{ 0x722c4746, __VMLINUX_SYMBOL_STR(_raw_write_lock_bh) },
	{ 0xf9bf4907, __VMLINUX_SYMBOL_STR(dev_uc_sync) },
	{ 0x6ac11fb4, __VMLINUX_SYMBOL_STR(netdev_lower_get_first_private_rcu) },
	{ 0xa0dad88e, __VMLINUX_SYMBOL_STR(netdev_adjacent_get_private) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0xb2af82e4, __VMLINUX_SYMBOL_STR(seq_release) },
	{ 0x241ee48a, __VMLINUX_SYMBOL_STR(netdev_all_upper_get_next_dev_rcu) },
	{ 0xb0e602eb, __VMLINUX_SYMBOL_STR(memmove) },
	{ 0x972f6c11, __VMLINUX_SYMBOL_STR(consume_skb) },
	{ 0x85670f1d, __VMLINUX_SYMBOL_STR(rtnl_is_locked) },
	{ 0x9ec377fd, __VMLINUX_SYMBOL_STR(sysfs_create_file_ns) },
	{ 0x42a6c36, __VMLINUX_SYMBOL_STR(dev_queue_xmit) },
	{ 0x62cc8289, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0xb5419b40, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x47c8baf4, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0xe8e687ca, __VMLINUX_SYMBOL_STR(skb_copy_bits) },
	{ 0x1580db20, __VMLINUX_SYMBOL_STR(dev_mc_sync) },
	{ 0x6e720ff2, __VMLINUX_SYMBOL_STR(rtnl_unlock) },
	{ 0xc58a8cd, __VMLINUX_SYMBOL_STR(netdev_increment_features) },
	{ 0xde9477f5, __VMLINUX_SYMBOL_STR(dev_get_stats) },
	{ 0x1aa19d8e, __VMLINUX_SYMBOL_STR(netdev_class_create_file_ns) },
	{ 0x2bae2108, __VMLINUX_SYMBOL_STR(dev_set_mtu) },
	{ 0xe914e41e, __VMLINUX_SYMBOL_STR(strcpy) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "6D21CA2DBFA14E6E9551C83");
