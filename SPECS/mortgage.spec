%define name mortgage
%define version 0.0.1
%define release 1

Summary: configures ldap for use in the BMC
Name: %{name}
Version: %{version}
Release: %{release}
Source0: %{name}-%{version}.tgz
License: GPL
Group: System Environment/Kernel
BuildRoot: %{_tmppath}/%{name}-%{version}-buildroot
BuildRequires: glibc-devel gcc-c++
BuildArch: x86_64
Url: http://www.oracle.com/
Provides: %{name} = %{version}-%{release}
%define debug_package %{nil}

%description
Calculates mortgage repayments

##########################################################################################
# BUILD-TIME SCRIPTS
##########################################################################################

%prep
true "=================================================================================="
true "BEG Build preprocess"
%setup -q

%pre

%build
make

%install
true "=================================================================================="
true "BEG Installation"

rm -rf %{buildroot}
mkdir -p %{buildroot}
# cd %{buildroot}
mkdir -p %{buildroot}/usr/bin
install -s -m 755 mortgage %{buildroot}/usr/bin/mortgage
mkdir -p %{buildroot}/%{_mandir}/man9/
cp mortgage.man  %{buildroot}/%{_mandir}/man9/mortgage.man

%post

%postun

%clean
rm -rf %{buildroot}

%files
%attr(0755,root,root) /usr/bin/mortgage
%attr(0755,root,root) %{_mandir}/man9/mortgage.man.gz

%changelog
* Mon Apr 10 2017 Tim Jinkerson <tim.jinkerson@oracle.com>
- Added a Man Page
* Tue Apr 04 2017 Tim Jinkerson <tim.jinkerson@oracle.com>
- Initial Build
