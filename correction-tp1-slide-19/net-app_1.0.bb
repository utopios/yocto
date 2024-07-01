DESCRIPTION = "Our first recipes hello"
SECTION = "examples"
LICENSE = "MIT"

LIC_FILES_CHKSUM = "file://${WORKDIR}/LICENSE;md5=089ae343023473b32aa5ef3d38a21300"

SRC_URI = "file://net-app.tar.gz"
SRC_URI[sha256sum] = "7ff0169bd148ca53e3c14cf62a587d574f35ebcaf8eb9f3848f2266c80a9224f"

do_unpack() {
	tar xzvf ${WORKDIR}/net-app.tar.gz -C ${WORKDIR}
}

do_configure() {
    :
}

do_compile() {
    oe_runmake
}

do_install() {
    install -d ${D}{$bindir}
    install -m 0755 net-app ${D}${bindir}/net-app
}
FILES_${PN} = "${bindir}/net-app"