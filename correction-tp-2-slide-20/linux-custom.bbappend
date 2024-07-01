FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI += "file://my_driver.patch"

do_configure:append() {
    patch -p1 < ${WORKDIR}/my_driver.patch
}