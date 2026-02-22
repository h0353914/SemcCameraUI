# Add project specific ProGuard rules here.
-keep class de.robv.android.xposed.** { *; }
-keepclasseswithmembers class * {
    public void handleLoadPackage(de.robv.android.xposed.callbacks.XC_LoadPackage.LoadPackageParam);
}
