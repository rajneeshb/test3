<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function new_hampshire_storefront_user_default_permissions() {
  $permissions = array();

  // Exported permission: Use PHP input for field settings (dangerous - grant with care)
  $permissions['Use PHP input for field settings (dangerous - grant with care)'] = array(
    'name' => 'Use PHP input for field settings (dangerous - grant with care)',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: access administration menu
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: access administration pages
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: access all views
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: access better messages
  $permissions['access better messages'] = array(
    'name' => 'access better messages',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: access comments
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: access content
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: access devel information
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: access site reports
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: access user profiles
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'avtranz',
      '3' => 'content provider',
      '4' => 'supervisor',
    ),
  );

  // Exported permission: administer account_profile
  $permissions['administer account_profile'] = array(
    'name' => 'administer account_profile',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'supervisor',
    ),
  );

  // Exported permission: administer actions
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer advanced pane settings
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer better messages
  $permissions['administer better messages'] = array(
    'name' => 'administer better messages',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer blocks
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer breadcrumbs
  $permissions['administer breadcrumbs'] = array(
    'name' => 'administer breadcrumbs',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer comments
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer content types
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer custom breadcrumbs
  $permissions['administer custom breadcrumbs'] = array(
    'name' => 'administer custom breadcrumbs',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer features
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer feeds
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer files
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer filters
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer front page
  $permissions['administer front page'] = array(
    'name' => 'administer front page',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer login destination
  $permissions['administer login destination'] = array(
    'name' => 'administer login destination',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer masquerade
  $permissions['administer masquerade'] = array(
    'name' => 'administer masquerade',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer menu
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer menu attributes
  $permissions['administer menu attributes'] = array(
    'name' => 'administer menu attributes',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer menu_per_role
  $permissions['administer menu_per_role'] = array(
    'name' => 'administer menu_per_role',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer multistep
  $permissions['administer multistep'] = array(
    'name' => 'administer multistep',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer nodes
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: administer page manager
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer pane access
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer pane visibility
  $permissions['administer pane visibility'] = array(
    'name' => 'administer pane visibility',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer panels layouts
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer pathauto
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer permissions
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer plupload bulk uploads
  $permissions['administer plupload bulk uploads'] = array(
    'name' => 'administer plupload bulk uploads',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: administer redirects
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer role change notification
  $permissions['administer role change notification'] = array(
    'name' => 'administer role change notification',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer rules
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer search
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer site configuration
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer taxonomy
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer theme assignments
  $permissions['administer theme assignments'] = array(
    'name' => 'administer theme assignments',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer themekey settings
  $permissions['administer themekey settings'] = array(
    'name' => 'administer themekey settings',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer url aliases
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer user read-only settings
  $permissions['administer user read-only settings'] = array(
    'name' => 'administer user read-only settings',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer users
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'supervisor',
    ),
  );

  // Exported permission: administer views
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: assign administrator role
  $permissions['assign administrator role'] = array(
    'name' => 'assign administrator role',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: assign all roles
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: assign avtranz role
  $permissions['assign avtranz role'] = array(
    'name' => 'assign avtranz role',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: assign content provider role
  $permissions['assign content provider role'] = array(
    'name' => 'assign content provider role',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'supervisor',
    ),
  );

  // Exported permission: assign customer role
  $permissions['assign customer role'] = array(
    'name' => 'assign customer role',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'supervisor',
    ),
  );

  // Exported permission: assign node themes
  $permissions['assign node themes'] = array(
    'name' => 'assign node themes',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: assign path alias themes
  $permissions['assign path alias themes'] = array(
    'name' => 'assign path alias themes',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: assign supervisor role
  $permissions['assign supervisor role'] = array(
    'name' => 'assign supervisor role',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: assign theme to own nodes
  $permissions['assign theme to own nodes'] = array(
    'name' => 'assign theme to own nodes',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: bulk upload files with plupload
  $permissions['bulk upload files with plupload'] = array(
    'name' => 'bulk upload files with plupload',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: change own username
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: clear tcro_order_updater feeds
  $permissions['clear tcro_order_updater feeds'] = array(
    'name' => 'clear tcro_order_updater feeds',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: clone node
  $permissions['clone node'] = array(
    'name' => 'clone node',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: clone own nodes
  $permissions['clone own nodes'] = array(
    'name' => 'clone own nodes',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: collapse format fieldset by default
  $permissions['collapse format fieldset by default'] = array(
    'name' => 'collapse format fieldset by default',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: collapsible format selection
  $permissions['collapsible format selection'] = array(
    'name' => 'collapsible format selection',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: create content_provider_group content
  $permissions['create content_provider_group content'] = array(
    'name' => 'create content_provider_group content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'supervisor',
    ),
  );

  // Exported permission: create court_type content
  $permissions['create court_type content'] = array(
    'name' => 'create court_type content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: create help content
  $permissions['create help content'] = array(
    'name' => 'create help content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: create story content
  $permissions['create story content'] = array(
    'name' => 'create story content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: create test_fields content
  $permissions['create test_fields content'] = array(
    'name' => 'create test_fields content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: create uploaded_file content
  $permissions['create uploaded_file content'] = array(
    'name' => 'create uploaded_file content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: create url aliases
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: create webform content
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any content_provider_group content
  $permissions['delete any content_provider_group content'] = array(
    'name' => 'delete any content_provider_group content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any court_type content
  $permissions['delete any court_type content'] = array(
    'name' => 'delete any court_type content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any help content
  $permissions['delete any help content'] = array(
    'name' => 'delete any help content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any order content
  $permissions['delete any order content'] = array(
    'name' => 'delete any order content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any order_payment content
  $permissions['delete any order_payment content'] = array(
    'name' => 'delete any order_payment content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any page content
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any profile content
  $permissions['delete any profile content'] = array(
    'name' => 'delete any profile content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'supervisor',
    ),
  );

  // Exported permission: delete any story content
  $permissions['delete any story content'] = array(
    'name' => 'delete any story content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any test_fields content
  $permissions['delete any test_fields content'] = array(
    'name' => 'delete any test_fields content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any uploaded_file content
  $permissions['delete any uploaded_file content'] = array(
    'name' => 'delete any uploaded_file content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'supervisor',
    ),
  );

  // Exported permission: delete any webform content
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own content_provider_group content
  $permissions['delete own content_provider_group content'] = array(
    'name' => 'delete own content_provider_group content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own court_type content
  $permissions['delete own court_type content'] = array(
    'name' => 'delete own court_type content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own help content
  $permissions['delete own help content'] = array(
    'name' => 'delete own help content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own order content
  $permissions['delete own order content'] = array(
    'name' => 'delete own order content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own order_payment content
  $permissions['delete own order_payment content'] = array(
    'name' => 'delete own order_payment content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own page content
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own profile content
  $permissions['delete own profile content'] = array(
    'name' => 'delete own profile content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own story content
  $permissions['delete own story content'] = array(
    'name' => 'delete own story content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own test_fields content
  $permissions['delete own test_fields content'] = array(
    'name' => 'delete own test_fields content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own uploaded_file content
  $permissions['delete own uploaded_file content'] = array(
    'name' => 'delete own uploaded_file content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'supervisor',
    ),
  );

  // Exported permission: delete own webform content
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete revisions
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: display drupal links
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: display source code
  $permissions['display source code'] = array(
    'name' => 'display source code',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit any content_provider_group content
  $permissions['edit any content_provider_group content'] = array(
    'name' => 'edit any content_provider_group content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'supervisor',
    ),
  );

  // Exported permission: edit any court_type content
  $permissions['edit any court_type content'] = array(
    'name' => 'edit any court_type content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit any help content
  $permissions['edit any help content'] = array(
    'name' => 'edit any help content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit any order content
  $permissions['edit any order content'] = array(
    'name' => 'edit any order content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: edit any order_payment content
  $permissions['edit any order_payment content'] = array(
    'name' => 'edit any order_payment content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit any page content
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit any profile content
  $permissions['edit any profile content'] = array(
    'name' => 'edit any profile content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'supervisor',
    ),
  );

  // Exported permission: edit any story content
  $permissions['edit any story content'] = array(
    'name' => 'edit any story content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit any test_fields content
  $permissions['edit any test_fields content'] = array(
    'name' => 'edit any test_fields content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit any uploaded_file content
  $permissions['edit any uploaded_file content'] = array(
    'name' => 'edit any uploaded_file content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'supervisor',
    ),
  );

  // Exported permission: edit any webform content
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_actual_cost
  $permissions['edit field_actual_cost'] = array(
    'name' => 'edit field_actual_cost',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: edit field_actual_pages
  $permissions['edit field_actual_pages'] = array(
    'name' => 'edit field_actual_pages',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: edit field_additional_comments
  $permissions['edit field_additional_comments'] = array(
    'name' => 'edit field_additional_comments',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_address
  $permissions['edit field_address'] = array(
    'name' => 'edit field_address',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_appeal_number
  $permissions['edit field_appeal_number'] = array(
    'name' => 'edit field_appeal_number',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_appealtranscript
  $permissions['edit field_appealtranscript'] = array(
    'name' => 'edit field_appealtranscript',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_associated_parties
  $permissions['edit field_associated_parties'] = array(
    'name' => 'edit field_associated_parties',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: edit field_avtcode
  $permissions['edit field_avtcode'] = array(
    'name' => 'edit field_avtcode',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_balance_due
  $permissions['edit field_balance_due'] = array(
    'name' => 'edit field_balance_due',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: edit field_balance_paid
  $permissions['edit field_balance_paid'] = array(
    'name' => 'edit field_balance_paid',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: edit field_balance_paid_date
  $permissions['edit field_balance_paid_date'] = array(
    'name' => 'edit field_balance_paid_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: edit field_case_number
  $permissions['edit field_case_number'] = array(
    'name' => 'edit field_case_number',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_casename
  $permissions['edit field_casename'] = array(
    'name' => 'edit field_casename',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_comments
  $permissions['edit field_comments'] = array(
    'name' => 'edit field_comments',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_company_firm
  $permissions['edit field_company_firm'] = array(
    'name' => 'edit field_company_firm',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_completed_transcript
  $permissions['edit field_completed_transcript'] = array(
    'name' => 'edit field_completed_transcript',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: edit field_completiondate
  $permissions['edit field_completiondate'] = array(
    'name' => 'edit field_completiondate',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: edit field_copy_order
  $permissions['edit field_copy_order'] = array(
    'name' => 'edit field_copy_order',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: edit field_court_location_groups
  $permissions['edit field_court_location_groups'] = array(
    'name' => 'edit field_court_location_groups',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'supervisor',
    ),
  );

  // Exported permission: edit field_court_pay_info
  $permissions['edit field_court_pay_info'] = array(
    'name' => 'edit field_court_pay_info',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_courttyperef
  $permissions['edit field_courttyperef'] = array(
    'name' => 'edit field_courttyperef',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
    ),
  );

  // Exported permission: edit field_create_or_login
  $permissions['edit field_create_or_login'] = array(
    'name' => 'edit field_create_or_login',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
    ),
  );

  // Exported permission: edit field_creator
  $permissions['edit field_creator'] = array(
    'name' => 'edit field_creator',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_daytime_phone
  $permissions['edit field_daytime_phone'] = array(
    'name' => 'edit field_daytime_phone',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_delivery_instructions
  $permissions['edit field_delivery_instructions'] = array(
    'name' => 'edit field_delivery_instructions',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_deposit_paid
  $permissions['edit field_deposit_paid'] = array(
    'name' => 'edit field_deposit_paid',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: edit field_deposit_paid_date
  $permissions['edit field_deposit_paid_date'] = array(
    'name' => 'edit field_deposit_paid_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: edit field_deposit_required
  $permissions['edit field_deposit_required'] = array(
    'name' => 'edit field_deposit_required',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: edit field_due_date
  $permissions['edit field_due_date'] = array(
    'name' => 'edit field_due_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: edit field_est_additional_cost
  $permissions['edit field_est_additional_cost'] = array(
    'name' => 'edit field_est_additional_cost',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_est_transcript_cost
  $permissions['edit field_est_transcript_cost'] = array(
    'name' => 'edit field_est_transcript_cost',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_estimated_cost
  $permissions['edit field_estimated_cost'] = array(
    'name' => 'edit field_estimated_cost',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: edit field_estimated_pages
  $permissions['edit field_estimated_pages'] = array(
    'name' => 'edit field_estimated_pages',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: edit field_estimatedhours
  $permissions['edit field_estimatedhours'] = array(
    'name' => 'edit field_estimatedhours',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_estimatedminutes
  $permissions['edit field_estimatedminutes'] = array(
    'name' => 'edit field_estimatedminutes',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_file
  $permissions['edit field_file'] = array(
    'name' => 'edit field_file',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_first_name
  $permissions['edit field_first_name'] = array(
    'name' => 'edit field_first_name',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_hearingdate
  $permissions['edit field_hearingdate'] = array(
    'name' => 'edit field_hearingdate',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_how_to_pay
  $permissions['edit field_how_to_pay'] = array(
    'name' => 'edit field_how_to_pay',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_last_name
  $permissions['edit field_last_name'] = array(
    'name' => 'edit field_last_name',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_locationref
  $permissions['edit field_locationref'] = array(
    'name' => 'edit field_locationref',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_numcopies
  $permissions['edit field_numcopies'] = array(
    'name' => 'edit field_numcopies',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_order_number
  $permissions['edit field_order_number'] = array(
    'name' => 'edit field_order_number',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: edit field_order_reference
  $permissions['edit field_order_reference'] = array(
    'name' => 'edit field_order_reference',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_orderstatus
  $permissions['edit field_orderstatus'] = array(
    'name' => 'edit field_orderstatus',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: edit field_otherformats
  $permissions['edit field_otherformats'] = array(
    'name' => 'edit field_otherformats',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_payment_amount
  $permissions['edit field_payment_amount'] = array(
    'name' => 'edit field_payment_amount',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_payment_order
  $permissions['edit field_payment_order'] = array(
    'name' => 'edit field_payment_order',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_payment_reason_code
  $permissions['edit field_payment_reason_code'] = array(
    'name' => 'edit field_payment_reason_code',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_payment_result
  $permissions['edit field_payment_result'] = array(
    'name' => 'edit field_payment_result',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_payment_serial_number
  $permissions['edit field_payment_serial_number'] = array(
    'name' => 'edit field_payment_serial_number',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_payment_serialized_data
  $permissions['edit field_payment_serialized_data'] = array(
    'name' => 'edit field_payment_serialized_data',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_private_pay_info
  $permissions['edit field_private_pay_info'] = array(
    'name' => 'edit field_private_pay_info',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_providergroupname
  $permissions['edit field_providergroupname'] = array(
    'name' => 'edit field_providergroupname',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_providernumber
  $permissions['edit field_providernumber'] = array(
    'name' => 'edit field_providernumber',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_providertype
  $permissions['edit field_providertype'] = array(
    'name' => 'edit field_providertype',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_testdate
  $permissions['edit field_testdate'] = array(
    'name' => 'edit field_testdate',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_testperson
  $permissions['edit field_testperson'] = array(
    'name' => 'edit field_testperson',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_transcribeextra
  $permissions['edit field_transcribeextra'] = array(
    'name' => 'edit field_transcribeextra',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_turnaroundtime
  $permissions['edit field_turnaroundtime'] = array(
    'name' => 'edit field_turnaroundtime',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: edit field_witnesses
  $permissions['edit field_witnesses'] = array(
    'name' => 'edit field_witnesses',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'customer',
      '6' => 'supervisor',
    ),
  );

  // Exported permission: edit own content_provider_group content
  $permissions['edit own content_provider_group content'] = array(
    'name' => 'edit own content_provider_group content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit own court_type content
  $permissions['edit own court_type content'] = array(
    'name' => 'edit own court_type content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit own help content
  $permissions['edit own help content'] = array(
    'name' => 'edit own help content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit own order content
  $permissions['edit own order content'] = array(
    'name' => 'edit own order content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: edit own order_payment content
  $permissions['edit own order_payment content'] = array(
    'name' => 'edit own order_payment content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit own page content
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit own profile content
  $permissions['edit own profile content'] = array(
    'name' => 'edit own profile content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'avtranz',
      '3' => 'content provider',
      '4' => 'supervisor',
    ),
  );

  // Exported permission: edit own story content
  $permissions['edit own story content'] = array(
    'name' => 'edit own story content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit own test_fields content
  $permissions['edit own test_fields content'] = array(
    'name' => 'edit own test_fields content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit own uploaded_file content
  $permissions['edit own uploaded_file content'] = array(
    'name' => 'edit own uploaded_file content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'supervisor',
    ),
  );

  // Exported permission: edit own webform content
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: execute php code
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: grant content access
  $permissions['grant content access'] = array(
    'name' => 'grant content access',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: grant own content access
  $permissions['grant own content access'] = array(
    'name' => 'grant own content access',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: import tcro_order_updater feeds
  $permissions['import tcro_order_updater feeds'] = array(
    'name' => 'import tcro_order_updater feeds',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: manage features
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: masquerade as admin
  $permissions['masquerade as admin'] = array(
    'name' => 'masquerade as admin',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: masquerade as user
  $permissions['masquerade as user'] = array(
    'name' => 'masquerade as user',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: notify of path changes
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: post comments
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: post comments without approval
  $permissions['post comments without approval'] = array(
    'name' => 'post comments without approval',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: revert revisions
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: save order for another user
  $permissions['save order for another user'] = array(
    'name' => 'save order for another user',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: search content
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: select different theme
  $permissions['select different theme'] = array(
    'name' => 'select different theme',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: show format selection for blocks
  $permissions['show format selection for blocks'] = array(
    'name' => 'show format selection for blocks',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: show format selection for comments
  $permissions['show format selection for comments'] = array(
    'name' => 'show format selection for comments',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: show format selection for nodes
  $permissions['show format selection for nodes'] = array(
    'name' => 'show format selection for nodes',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: show format tips
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: show more format tips link
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: switch users
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: toggle multistep
  $permissions['toggle multistep'] = array(
    'name' => 'toggle multistep',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: use PHP for block visibility
  $permissions['use PHP for block visibility'] = array(
    'name' => 'use PHP for block visibility',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: use PHP for title patterns
  $permissions['use PHP for title patterns'] = array(
    'name' => 'use PHP for title patterns',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: use admin toolbar
  $permissions['use admin toolbar'] = array(
    'name' => 'use admin toolbar',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: use advanced search
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: use page manager
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: use panels caching features
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: use panels dashboard
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: use panels in place editing
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: use php in custom breadcrumbs
  $permissions['use php in custom breadcrumbs'] = array(
    'name' => 'use php in custom breadcrumbs',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view advanced help index
  $permissions['view advanced help index'] = array(
    'name' => 'view advanced help index',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view advanced help popup
  $permissions['view advanced help popup'] = array(
    'name' => 'view advanced help popup',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view advanced help topic
  $permissions['view advanced help topic'] = array(
    'name' => 'view advanced help topic',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view all panes
  $permissions['view all panes'] = array(
    'name' => 'view all panes',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view date repeats
  $permissions['view date repeats'] = array(
    'name' => 'view date repeats',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view field_actual_cost
  $permissions['view field_actual_cost'] = array(
    'name' => 'view field_actual_cost',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: view field_actual_pages
  $permissions['view field_actual_pages'] = array(
    'name' => 'view field_actual_pages',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: view field_additional_comments
  $permissions['view field_additional_comments'] = array(
    'name' => 'view field_additional_comments',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_address
  $permissions['view field_address'] = array(
    'name' => 'view field_address',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_appeal_number
  $permissions['view field_appeal_number'] = array(
    'name' => 'view field_appeal_number',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_appealtranscript
  $permissions['view field_appealtranscript'] = array(
    'name' => 'view field_appealtranscript',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_associated_parties
  $permissions['view field_associated_parties'] = array(
    'name' => 'view field_associated_parties',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: view field_avtcode
  $permissions['view field_avtcode'] = array(
    'name' => 'view field_avtcode',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: view field_balance_due
  $permissions['view field_balance_due'] = array(
    'name' => 'view field_balance_due',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: view field_balance_paid
  $permissions['view field_balance_paid'] = array(
    'name' => 'view field_balance_paid',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: view field_balance_paid_date
  $permissions['view field_balance_paid_date'] = array(
    'name' => 'view field_balance_paid_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  // Exported permission: view field_case_number
  $permissions['view field_case_number'] = array(
    'name' => 'view field_case_number',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_casename
  $permissions['view field_casename'] = array(
    'name' => 'view field_casename',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_comments
  $permissions['view field_comments'] = array(
    'name' => 'view field_comments',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_company_firm
  $permissions['view field_company_firm'] = array(
    'name' => 'view field_company_firm',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_completed_transcript
  $permissions['view field_completed_transcript'] = array(
    'name' => 'view field_completed_transcript',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: view field_completiondate
  $permissions['view field_completiondate'] = array(
    'name' => 'view field_completiondate',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_copy_order
  $permissions['view field_copy_order'] = array(
    'name' => 'view field_copy_order',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
    ),
  );

  // Exported permission: view field_court_location_groups
  $permissions['view field_court_location_groups'] = array(
    'name' => 'view field_court_location_groups',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: view field_court_pay_info
  $permissions['view field_court_pay_info'] = array(
    'name' => 'view field_court_pay_info',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_courttyperef
  $permissions['view field_courttyperef'] = array(
    'name' => 'view field_courttyperef',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_create_or_login
  $permissions['view field_create_or_login'] = array(
    'name' => 'view field_create_or_login',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view field_creator
  $permissions['view field_creator'] = array(
    'name' => 'view field_creator',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_daytime_phone
  $permissions['view field_daytime_phone'] = array(
    'name' => 'view field_daytime_phone',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_delivery_instructions
  $permissions['view field_delivery_instructions'] = array(
    'name' => 'view field_delivery_instructions',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_deposit_paid
  $permissions['view field_deposit_paid'] = array(
    'name' => 'view field_deposit_paid',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
    ),
  );

  // Exported permission: view field_deposit_paid_date
  $permissions['view field_deposit_paid_date'] = array(
    'name' => 'view field_deposit_paid_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
    ),
  );

  // Exported permission: view field_deposit_required
  $permissions['view field_deposit_required'] = array(
    'name' => 'view field_deposit_required',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
    ),
  );

  // Exported permission: view field_due_date
  $permissions['view field_due_date'] = array(
    'name' => 'view field_due_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_est_additional_cost
  $permissions['view field_est_additional_cost'] = array(
    'name' => 'view field_est_additional_cost',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_est_transcript_cost
  $permissions['view field_est_transcript_cost'] = array(
    'name' => 'view field_est_transcript_cost',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_estimated_cost
  $permissions['view field_estimated_cost'] = array(
    'name' => 'view field_estimated_cost',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_estimated_pages
  $permissions['view field_estimated_pages'] = array(
    'name' => 'view field_estimated_pages',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
    ),
  );

  // Exported permission: view field_estimatedhours
  $permissions['view field_estimatedhours'] = array(
    'name' => 'view field_estimatedhours',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_estimatedminutes
  $permissions['view field_estimatedminutes'] = array(
    'name' => 'view field_estimatedminutes',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_file
  $permissions['view field_file'] = array(
    'name' => 'view field_file',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
    ),
  );

  // Exported permission: view field_first_name
  $permissions['view field_first_name'] = array(
    'name' => 'view field_first_name',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_hearingdate
  $permissions['view field_hearingdate'] = array(
    'name' => 'view field_hearingdate',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_how_to_pay
  $permissions['view field_how_to_pay'] = array(
    'name' => 'view field_how_to_pay',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_last_name
  $permissions['view field_last_name'] = array(
    'name' => 'view field_last_name',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_locationref
  $permissions['view field_locationref'] = array(
    'name' => 'view field_locationref',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_numcopies
  $permissions['view field_numcopies'] = array(
    'name' => 'view field_numcopies',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_order_number
  $permissions['view field_order_number'] = array(
    'name' => 'view field_order_number',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_order_reference
  $permissions['view field_order_reference'] = array(
    'name' => 'view field_order_reference',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view field_orderstatus
  $permissions['view field_orderstatus'] = array(
    'name' => 'view field_orderstatus',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_otherformats
  $permissions['view field_otherformats'] = array(
    'name' => 'view field_otherformats',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_payment_amount
  $permissions['view field_payment_amount'] = array(
    'name' => 'view field_payment_amount',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view field_payment_order
  $permissions['view field_payment_order'] = array(
    'name' => 'view field_payment_order',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view field_payment_reason_code
  $permissions['view field_payment_reason_code'] = array(
    'name' => 'view field_payment_reason_code',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view field_payment_result
  $permissions['view field_payment_result'] = array(
    'name' => 'view field_payment_result',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view field_payment_serial_number
  $permissions['view field_payment_serial_number'] = array(
    'name' => 'view field_payment_serial_number',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view field_payment_serialized_data
  $permissions['view field_payment_serialized_data'] = array(
    'name' => 'view field_payment_serialized_data',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view field_private_pay_info
  $permissions['view field_private_pay_info'] = array(
    'name' => 'view field_private_pay_info',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_providergroupname
  $permissions['view field_providergroupname'] = array(
    'name' => 'view field_providergroupname',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_providernumber
  $permissions['view field_providernumber'] = array(
    'name' => 'view field_providernumber',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: view field_providertype
  $permissions['view field_providertype'] = array(
    'name' => 'view field_providertype',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: view field_testdate
  $permissions['view field_testdate'] = array(
    'name' => 'view field_testdate',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: view field_testperson
  $permissions['view field_testperson'] = array(
    'name' => 'view field_testperson',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: view field_transcribeextra
  $permissions['view field_transcribeextra'] = array(
    'name' => 'view field_transcribeextra',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_turnaroundtime
  $permissions['view field_turnaroundtime'] = array(
    'name' => 'view field_turnaroundtime',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'supervisor',
    ),
  );

  // Exported permission: view field_witnesses
  $permissions['view field_witnesses'] = array(
    'name' => 'view field_witnesses',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'avtranz',
      '4' => 'content provider',
      '5' => 'customer',
      '6' => 'supervisor',
    ),
  );

  // Exported permission: view order administration list
  $permissions['view order administration list'] = array(
    'name' => 'view order administration list',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'supervisor',
    ),
  );

  // Exported permission: view order administration list by location
  $permissions['view order administration list by location'] = array(
    'name' => 'view order administration list by location',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
      '2' => 'content provider',
      '3' => 'supervisor',
    ),
  );

  // Exported permission: view pane admin links
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view revisions
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'avtranz',
    ),
  );

  return $permissions;
}
