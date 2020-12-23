#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
 
static int pen_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    printk(KERN_INFO "Kernel Bois Pen drive (%04X:%04X) plugged\n", id->idVendor, id->idProduct);
    return 0;
}
 
static void pen_disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "Kernel Bois Pen drive removed\n");
}
 
static struct usb_device_id pen_table[] =
{
    { USB_DEVICE(0x0930, 0x6544) },
    {} /* Terminating entry */
};
MODULE_DEVICE_TABLE (usb, pen_table);
 
static struct usb_driver pen_driver =
{
    .name = "pen_driver",
    .id_table = pen_table,
    .probe = pen_probe,
    .disconnect = pen_disconnect,
};
 
static int __init pen_init(void)
{
    int ret = -1;
    printk(KERN_INFO "[*] Kernel Bois USB Driver");
    printk(KERN_INFO "\tRegistering Kernel Bois USB Driver with Kernel");
    ret = usb_register(&pen_driver);
    printk(KERN_INFO "\tRegistration is complete");
    return ret;
}
 
static void __exit pen_exit(void)
{
    printk(KERN_INFO "[*] Kernel Bois USB Driver");
    usb_deregister(&pen_driver);
    printk(KERN_INFO "\tUnregistration is complete");
}
 
module_init(pen_init);
module_exit(pen_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Stefanus Khrisna A. H. 1706074921");
MODULE_DESCRIPTION("USB Kernel Bois Pen Registration Driver");
