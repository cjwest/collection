<?php
/**
 * @file
 * my_collection_layout.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function my_collection_layout_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'collection_node';
  $context->description = 'My Articles for my collection';
  $context->tag = 'My Collection';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'my_collection' => 'my_collection',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-collection_article_list-block' => array(
          'module' => 'views',
          'delta' => 'collection_article_list-block',
          'region' => 'content_lower',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('My Articles for my collection');
  t('My Collection');
  $export['collection_node'] = $context;

  return $export;
}
